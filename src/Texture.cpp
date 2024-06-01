



#include "Texture.hpp"
#include "allegro5/allegro.h"
#include "allegro5/allegro_opengl.h"



extern const TexID BAD_TEXID = TexID();



TexID::TexID() :
      tid((GLuint)-1),
      bmp(0)
{}



TexID::TexID(ALLEGRO_BITMAP* tex) :
      tid((GLuint)-1),
      bmp(tex)
{
   if (tex) {
      tid = al_get_opengl_texture(tex);
   }
}



void TexLib::Clear() {
   for (std::map<std::string , TexID>::iterator it = texlib.begin() ; it != texlib.end() ; ++it) {
      TexID& tid = it->second;
      if (tid.bmp) {
         al_destroy_bitmap(tid.bmp);
         tid.bmp = 0;
      }
   }
   texlib.clear();
}



TexID TexLib::LoadTexture(std::string image_file) {
   ALLEGRO_BITMAP* tex = al_load_bitmap(image_file.c_str());
   if (tex) {
      texlib[image_file] = TexID(tex);
      return texlib[image_file];
   }
   return BAD_TEXID;
}



TexID TexLib::TID(std::string texname) {
   if (texlib.find(texname) == texlib.end()) {
      return LoadTexture(texname);
   }
   return texlib[texname];
}



