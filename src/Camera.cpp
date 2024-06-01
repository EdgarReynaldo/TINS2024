



#include "Camera.hpp"

#include "Eagle/Math.hpp"
#include "allegro5/allegro.h"


Camera::Camera() :
      info(START),
      hfov(6.0*M_PI/12.0),/// In RADIANS (PI/2 (90 degrees) looks best, with the least distortion)
      aspect(16.0/9.0),
      ortho(false)
{}



void Camera::Setup3D(bool orthographic) {
   ortho  = orthographic;
   ALLEGRO_TRANSFORM proj;
   ALLEGRO_TRANSFORM cam;
   
   const double near = 1.0;
   const double w = near*tan(hfov/2.0);

///   const double l = -w;
///   const double r = w;
   
   /** l and r are reversed to fix the axes */
   const double l = w;
   const double r = -w;
   
   const double top = w/aspect;
   const double bot = -w/aspect;
   const double far = 2000.0;

   
   al_identity_transform(&proj);
   if (!ortho) {
      al_perspective_transform(&proj , l , top , near , r , bot , far);
   }
   else {
      int diam = 500;
      al_orthographic_transform(&proj , -diam , diam , -diam , diam , -diam , diam);
   }
   al_use_projection_transform(&proj);
   
   Vec3 eye = info.pos;
   Vec3 look = info.pos + info.orient.Fw();
   Vec3 up = info.orient.Up();
   
   al_identity_transform(&cam);
   al_build_camera_transform(&cam , eye.x , eye.y , eye.z , look.x , look.y , look.z , up.x , up.y , up.z);
///   al_scale_transform_3d(&cam , 1.0 , 1.0 , 1.0);
   al_use_transform(&cam);
}



void Camera::Setup2D() {
   ALLEGRO_TRANSFORM tr;
   al_identity_transform(&tr);
   al_orthographic_transform(&tr , 0 , 0 , -1.0 , al_get_display_width(al_get_current_display()) , al_get_display_height(al_get_current_display()) , 1.0);
   al_use_projection_transform(&tr);
   
   al_identity_transform(&tr);
   al_use_transform(&tr);
}



void Camera::Move(Vec3 vel , double dt) {
   vel*=dt;
   Vec3 fw = info.orient.Fw();
   Vec3 rt = info.orient.Rt();
   Vec3 up = info.orient.Up();
   info.pos += rt*vel.x + up*vel.y + fw*vel.z;
}



void Camera::Turn(Vec3 omega , double dt) {
   info.orient.TurnLocal(omega , dt);
}


