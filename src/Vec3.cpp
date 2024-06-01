



#include "Vec3.hpp"


#include "allegro5/allegro.h"


#include <cstdio>


const Vec3 ORIGIN(0,0,0);

const Vec3 UP(0,1,0);
const Vec3 RIGHT(1,0,0);
const Vec3 FORWARD(0,0,1);



Vec3 Rotate3D(const Vec3& vec , const Vec3& axis , const double theta_radians) {
   /// TODO : This uses allegro's transformation matrices, which only use floating point precision
   /// TODO : This could be a source of rounding errors
   ALLEGRO_TRANSFORM t;
   
   al_identity_transform(&t);
   al_rotate_transform_3d(&t , axis.x , axis.y , axis.z , theta_radians);
   
   /// Note the use of floats here
   float fx = vec.x;
   float fy = vec.y;
   float fz = vec.z;
   
   al_transform_coordinates_3d(&t , &fx , &fy , &fz);
   
   return Vec3(fx,fy,fz);
}



bool ScanVec3(const char* str , Vec3& v) {
   return 3 == sscanf(str , "%lf%lf%lf" , &v.x , &v.y , &v.z);
}



