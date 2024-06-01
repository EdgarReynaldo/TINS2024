



#include "Editor.hpp"
#include "BasicAllegro.hpp"
#include "Input.hpp"
#include "CrossSection.hpp"
#include "CrossSectionTypes.hpp"
#include "Drawing.hpp"
#include "Math.hpp"


bool ortho = false;

Editor::Editor() : 
      Scene(),
      cam(),
      track1(),
      track2(),
      track3(),
      track4(),
      track5(),
      cam_speed(33.4),
      cam_turn_rate(2.0*M_PI/12.0),
///      skybox("Data/Skybox/Space1.png")
///      skybox("Data/Skybox/GreenSpace1.png")
      skybox("Data/Skybox/SkyboxA.png")
///      skybox("Data/Skybox/KorzonSkybox.png")
{
   cam.SetPos(ORIGIN - START.orient.Fw()*10.0 + START.orient.Up()*10.0);

   
   track1.AddSegment(TrackSegment(new TSG<Turn>(Turn(-50,150))) , CSG(new CurvedCSG(Curve(new Span(50)))));

   track2.AddSegment(TrackSegment(new TSG<StraightAway>(StraightAway(100.0)))                    , CSG(new CurvedCSG(Curve(new Span(50)))));
   track2.AddSegment(TrackSegment(new TSG<CurvedTrack> (CurvedTrack(M_PI , M_PI/2.0 , 315)))   , CSG(new CurvedCSG(Curve(new Span(50)))));
   track2.AddSegment(TrackSegment(new TSG<StraightAway>(StraightAway(100.0)))                    , CSG(new CurvedCSG(Curve(new Span(50)))));
   track2.AddSegment(TrackSegment(new TSG<CurvedTrack> (CurvedTrack(M_PI , M_PI/2.0 , 315)))   , CSG(new CurvedCSG(Curve(new Span(50)))));
   
///   track3.AddSegment(TrackSegment(new TSG<Turn>(Turn(150 , 50)))                                 , CSG(new CurvedCSG(Curve(new Span(50)))));
   track3.AddSegment(TrackSegment(new TSG<Turn>(Turn(150 , 50)))                                 , 
                     CSG(new CurvedCSG(Curve(new Span(50)))));

   track4.AddSegment(TrackSegment(new TSG<CurvedTrack>(CurvedTrack(2.0*M_PI , M_PI , 500.0)))    , CSG(new CurvedCSG(Curve(new Span(50)))));
   track5.AddSegment(TrackSegment(new TSG<CurvedTrack>(CurvedTrack(2.0*M_PI , 0.0 , 1000.0)))  , CSG(new CurvedCSG(Curve(new Span(50)))));
   
   
   
   track1.BuildTrack();
   track2.BuildTrack();
   track3.BuildTrack();
   track4.BuildTrack();
   track5.BuildTrack();
   
///   if (!track4.BuildTrack() || !track5.BuildTrack()) {
///      printf("Failed to build track.\n");
///   }
}



STATUS Editor::HandleEvent(ALLEGRO_EVENT ev) {
   STATUS s = Scene::HandleEvent(ev);
   if (s == STATUS_QUIT) {return s;}
   
   if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_P) {
      ortho = !ortho;
   }
   
   /// INPUT HANDLING
   if (ev.type == ALLEGRO_EVENT_TIMER) {
      /// X movement
      if (keys[ALLEGRO_KEY_LEFT] || keys[ALLEGRO_KEY_RIGHT]) {
         cam.Move(Vec3((keys[ALLEGRO_KEY_LEFT])?-cam_speed:cam_speed , 0 , 0) , SPT);
      }
      /// Y movement
      if (keys[ALLEGRO_KEY_PGDN] || keys[ALLEGRO_KEY_PGUP]) {
         cam.Move(Vec3(0 , cam_speed*((keys[ALLEGRO_KEY_PGDN] || keys[ALLEGRO_KEY_RSHIFT])?-1:1) , 0) , SPT);
      }
      /// Z movement 
      if (keys[ALLEGRO_KEY_UP] || keys[ALLEGRO_KEY_DOWN]) {
         cam.Move(Vec3(0 , 0 , (keys[ALLEGRO_KEY_DOWN])?-cam_speed:cam_speed) , SPT);
      }
      /// YAW
      if (keys[ALLEGRO_KEY_PAD_4] || keys[ALLEGRO_KEY_PAD_6]) {
         cam.Turn(Vec3((keys[ALLEGRO_KEY_PAD_4]?-cam_turn_rate:cam_turn_rate) , 0 , 0) , SPT);
      }
      /// PITCH
      if (keys[ALLEGRO_KEY_PAD_2] || keys[ALLEGRO_KEY_PAD_8]) {
         cam.Turn(Vec3(0 , (keys[ALLEGRO_KEY_PAD_2]?-cam_turn_rate:cam_turn_rate) , 0) , SPT);
      }
      /// ROLL
      if (keys[ALLEGRO_KEY_PAD_7] || keys[ALLEGRO_KEY_PAD_9]) {
         cam.Turn(Vec3(0 , 0 , (keys[ALLEGRO_KEY_PAD_7]?cam_turn_rate:-cam_turn_rate)) , SPT);
      }
   }
   return STATUS_OK;
}



void Editor::Display() {
   al_set_target_backbuffer(d);


   cam.Setup3D(false);

   glDisable(GL_DEPTH_TEST);
   glClear(GL_DEPTH_BUFFER_BIT);

   glFrontFace(GL_CW);
   glEnable(GL_TEXTURE_2D);
   skybox.Render(cam.Pos());
   glDisable(GL_TEXTURE_2D);
   
   glFrontFace(GL_CCW);
   glEnable(GL_DEPTH_TEST);
   glClear(GL_DEPTH_BUFFER_BIT);
   
   cam.Setup3D(ortho);

   track1.Draw();
   track2.Draw();
   track3.Draw();
   track4.Draw();
   track5.Draw();
/**   
   Camera::Setup2D();
   Vec3 campos = cam.Pos();
   al_draw_textf(f , al_map_rgb(255,255,255) , 10 , sh - (10 + al_get_font_line_height(f)) , ALLEGRO_ALIGN_LEFT , 
                 "CamPos = %1.2lf , %1.2lf , %1.2lf" , campos.x , campos.y , campos.z);
*/
   
   SpatialInfo s = START;
   s.pos += s.orient.Up()*10.0;
   const double length = 10.0;
   

   DrawLine(s.pos , s.pos + 2.0*length*UP , al_map_rgba(0,255,0,255));;
   DrawLine(s.pos , s.pos + 2.0*length*RIGHT , al_map_rgba(255,0,0,255));;
   DrawLine(s.pos , s.pos + 2.0*length*FORWARD , al_map_rgba(0,0,255,255));;

   s.pos -= 10.0*RIGHT;
   
   DrawLine(s.pos , s.pos + length*s.orient.Up() , al_map_rgba(0,127,0,255));;
   DrawLine(s.pos , s.pos + length*s.orient.Rt() , al_map_rgba(127,0,0,255));;
   DrawLine(s.pos , s.pos + length*s.orient.Fw() , al_map_rgba(0,0,127,255));;
      
   redraw = false;
}



STATUS Editor::Update(double dt) {
   if (dt > 0.0) {redraw = true;}
   return STATUS_OK;
}
