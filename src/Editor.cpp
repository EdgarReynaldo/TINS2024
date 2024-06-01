



#include "Eagle/InputHandler.hpp"
#include "Eagle/Math.hpp"

#include "Editor.hpp"
#include "CrossSection.hpp"
#include "CrossSectionTypes.hpp"
#include "Drawing.hpp"


bool ortho = false;

Editor::Editor() : 
      Scene(),
      cam(),
      track1(),
      cam_speed(33.4),
      cam_turn_rate(2.0*M_PI/12.0),
///      skybox("Data/Skybox/Space1.png")
///      skybox("Data/Skybox/GreenSpace1.png")
      skybox("Data/Skybox/SkyboxA.png")
///      skybox("Data/Skybox/KorzonSkybox.png")
{
   cam.SetPos(ORIGIN - START.orient.Fw()*10.0 + START.orient.Up()*10.0);

   track1.AddSegment(TrackSegment(new TSG<StraightAway>(StraightAway(100.0)))                    , CSG(new CurvedCSG(Curve(new Span(50)))));
   track1.AddSegment(TrackSegment(new TSG<CurvedTrack> (CurvedTrack(M_PI , M_PI/2.0 , 315)))   , CSG(new CurvedCSG(Curve(new Span(50)))));
   track1.AddSegment(TrackSegment(new TSG<StraightAway>(StraightAway(100.0)))                    , CSG(new CurvedCSG(Curve(new Span(50)))));
   track1.AddSegment(TrackSegment(new TSG<CurvedTrack> (CurvedTrack(M_PI , M_PI/2.0 , 315)))   , CSG(new CurvedCSG(Curve(new Span(50)))));
   
   track1.BuildTrack();
}



STATUS Editor::HandleEvent(EagleEvent ev) {
   
   if (ev.type == EAGLE_EVENT_KEY_DOWN && ev.keyboard.keycode == EAGLE_KEY_P) {
      ortho = !ortho;
   }
   
   /// INPUT HANDLING
   if (ev.type == EAGLE_EVENT_TIMER) {
      /// X movement
      if (keydown[EAGLE_KEY_LEFT] || keydown[EAGLE_KEY_RIGHT]) {
         cam.Move(Vec3((keydown[EAGLE_KEY_LEFT])?-cam_speed:cam_speed , 0 , 0) , SPT);
      }
      /// Y movement
      if (keydown[EAGLE_KEY_PGDN] || keydown[EAGLE_KEY_PGUP]) {
         cam.Move(Vec3(0 , cam_speed*((keydown[EAGLE_KEY_PGDN] || keydown[EAGLE_KEY_RSHIFT])?-1:1) , 0) , SPT);
      }
      /// Z movement 
      if (keydown[EAGLE_KEY_UP] || keydown[EAGLE_KEY_DOWN]) {
         cam.Move(Vec3(0 , 0 , (keydown[EAGLE_KEY_DOWN])?-cam_speed:cam_speed) , SPT);
      }
      /// YAW
      if (keydown[EAGLE_KEY_PAD_4] || keydown[EAGLE_KEY_PAD_6]) {
         cam.Turn(Vec3((keydown[EAGLE_KEY_PAD_4]?-cam_turn_rate:cam_turn_rate) , 0 , 0) , SPT);
      }
      /// PITCH
      if (keydown[EAGLE_KEY_PAD_2] || keydown[EAGLE_KEY_PAD_8]) {
         cam.Turn(Vec3(0 , (keydown[EAGLE_KEY_PAD_2]?-cam_turn_rate:cam_turn_rate) , 0) , SPT);
      }
      /// ROLL
      if (keydown[EAGLE_KEY_PAD_7] || keydown[EAGLE_KEY_PAD_9]) {
         cam.Turn(Vec3(0 , 0 , (keydown[EAGLE_KEY_PAD_7]?cam_turn_rate:-cam_turn_rate)) , SPT);
      }
   }
   return STATUS_OK;
}



void Editor::Display(EagleGraphicsContext* win) {
   
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
/**   
   Camera::Setup2D();
   Vec3 campos = cam.Pos();
   al_draw_textf(f , al_map_rgb(255,255,255) , 10 , sh - (10 + al_get_font_line_height(f)) , EAGLE_ALIGN_LEFT , 
                 "CamPos = %1.2lf , %1.2lf , %1.2lf" , campos.x , campos.y , campos.z);
*/
   
   SpatialInfo s = START;
   s.pos += s.orient.Up()*10.0;
   const double length = 10.0;
   
   /// Draw some axes at the track start
   DrawLine(s.pos , s.pos + 2.0*length*UP , EagleColor(0,255,0,255));;
   DrawLine(s.pos , s.pos + 2.0*length*RIGHT , EagleColor(255,0,0,255));;
   DrawLine(s.pos , s.pos + 2.0*length*FORWARD , EagleColor(0,0,255,255));;

   s.pos -= 10.0*RIGHT;
   
   DrawLine(s.pos , s.pos + length*s.orient.Up() , EagleColor(0,127,0,255));;
   DrawLine(s.pos , s.pos + length*s.orient.Rt() , EagleColor(127,0,0,255));;
   DrawLine(s.pos , s.pos + length*s.orient.Fw() , EagleColor(0,0,127,255));;
   
}



STATUS Editor::Update(double dt) {
   return STATUS_OK;
}
