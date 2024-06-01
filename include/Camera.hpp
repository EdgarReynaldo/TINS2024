



#ifndef Camera_HPP
#define Camera_HPP



#include "SpatialInfo.hpp"



class Camera {

protected :
   SpatialInfo info;

   double hfov;
   double aspect;/// w/h
   
   bool ortho;
   
public :
   
   Camera();
   
   Camera(Vec3 pos , Orient o , double hview , double aspect_ratio) : info(pos,o) , hfov(hview) , aspect(aspect_ratio) {}
   
   void SetPos(Vec3 p) {info.pos = p;}
   void SetOrientation(Orient o) {info.orient = o;}
   void SetHFOV(double v) {hfov = v;}
   void SetAspect(double a) {aspect = a;}
   
   void Setup3D(bool orthographic);
   static void Setup2D();
   
   const SpatialInfo& Info() {return info;}
   
   
   void Move(Vec3 vel , double dt);/// relative to orientation
   void Turn(Vec3 omega , double dt);/// relative to orientation
   
   inline Vec3 Pos() {return info.pos;}
   inline Orient Orientation() {return info.orient;}
   inline bool Ortho() {return ortho;}
};




#endif // Camera_HPP
