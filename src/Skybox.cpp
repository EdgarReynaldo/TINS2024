



#include "Skybox.hpp"
#include "Exception.hpp"




void Skybox::Clear() {
   
   if (sbimage) {
      al_destroy_bitmap(sbimage);
      sbimage = 0;
   }
   for(unsigned int i = 0 ; i < NUM_CUBE_FACES ; ++i) {
      if (sbfaces[i]) {
         al_destroy_bitmap(sbfaces[i]);   
         sbfaces[i] = 0;
      }
   }
}



void Skybox::MakeSkybox(const char* skybox_file) {
   Clear();
   
   sbimage = al_load_bitmap(skybox_file);
   EAGLE_ASSERT(sbimage);
   
   int tw = al_get_bitmap_width(sbimage);
   int th = al_get_bitmap_height(sbimage);
   EAGLE_ASSERT(tw*3 == th*4);/// Enforce aspect ration of skybox image - it should be a grid of 4x3 squares, any size
/*   
enum CUBE_FACE {
   CUBE_FACE_LEFT   = 0,
   CUBE_FACE_RIGHT  = 1,
   CUBE_FACE_TOP    = 2,
   CUBE_FACE_BOTTOM = 3,
   CUBE_FACE_BACK   = 4,
   CUBE_FACE_FRONT  = 5,
   NUM_CUBE_FACES   = 6
};
*/
   const int x[NUM_CUBE_FACES] = {
      0 , tw/2 , tw/4 , tw/4 , tw/4 , 3*tw/4
   };
   const int y[NUM_CUBE_FACES] = {
      th/3 , th/3 , 0 , 2*th/3 , th/3 , th/3
   };
   const int w = tw/4;
   const int h = th/3;
   EAGLE_ASSERT(w == h);/// Each side of the cube must be square
   
   for(unsigned int i = 0 ; i < NUM_CUBE_FACES ; ++i) {
      ALLEGRO_BITMAP* sub = al_create_sub_bitmap(sbimage , x[i] , y[i] , w , h);
      ALLEGRO_BITMAP* tex = al_clone_bitmap(sub);
///      ALLEGRO_BITMAP* tex = al_create_bitmap(w + 2 , h + 2);
///      ALLEGRO_BITMAP* tex = al_create_bitmap(w  , h );
///      al_set_target_bitmap(tex);
///      al_clear_to_color(al_map_rgba(0,0,0,0));
///      al_draw_bitmap_region(sbimage , x[i] , y[i] , w , h , 1 , 1 , 0);
      sbfaces[i] = tex;
      al_destroy_bitmap(sub);
   }
   sbcube.Texture(sbfaces);
}



Skybox::Skybox(const char* skybox_file) :
      sbcube(),
      sbimage(0),
      sbfaces()
{
   
   for(unsigned int i = 0 ; i < NUM_CUBE_FACES ; ++i) {sbfaces[i] = 0;}
   MakeSkybox(skybox_file);
}



void Skybox::Render(Vec3 pos) {
   glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_CLAMP_TO_EDGE);
   glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_CLAMP_TO_EDGE);
   sbcube.Inside().RenderTexturedFacesFront(SpatialInfo(pos , Orient()) , Vec3(500,500,500));
///      sbcube.Outside().RenderFaces(SpatialInfo() , Vec3(10,10,10));
}




