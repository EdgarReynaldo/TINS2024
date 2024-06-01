



#include "TrackGen.hpp"
#include "Exception.hpp"
#include "Math.hpp"



SpatialInfo StraightAway::Eval(const SpatialInfo& start , double pct) {
   SpatialInfo current = start;
   current.pos += start.orient.Fw()*l*pct;
   return current;
}



SpatialInfo Turn::Eval(const SpatialInfo& start , double pct) {
   if (pct <= 0.0) {return start;}
   if (pct > 1.0) {pct = 1.0;}
   
   SpatialInfo current = start;

   const double yaw = pct*M_PI/2.0;
   
///   double rad = w + (h-w)*pct;
   
   current.pos += start.orient.Rt()*w*(cos(pct*M_PI/2.0) - 1.0);
   current.pos += start.orient.Fw()*h*sin(pct*M_PI/2.0);

   current.orient.Turn(Vec3(yaw , 0 , 0) , 1.0);
   
   /// X coord is w*sin(t*PI/2)
   /// Y coord is h*sin(t*PI/2)
   /// Y coord is forward movement
   /// X coord is lateral movement
   
   return current;
}



double Turn::CalcLength() {
   const double a = abs(w);
   const double b = abs(h);
   const double k = (a-b)*(a-b)/((a+b)*(a+b));
   
   const double left = M_PI*(a+b);
   double right = 1.0;
   right += k/4.0;
   right += k*k/64.0;
   right += k*k*k/256.0;
   right += k*k*k*k*25.0/16384.0;
   right += k*k*k*k*k*49.0/65536.0;
   right += k*k*k*k*k*k*441.0/1048576.0;
   return left*right/4.0;// quarter ellipse
}




/// ------------------------       CurvedTrack     ---------------------------------------



SpatialInfo CurvedTrack::Eval(const SpatialInfo& start , double pct) {
   if (pct <= 0.0) {return start;}
   if (pct > 1.0) {pct = 1.0;}
   
   /// First find the radius of the curve
   EAGLE_ASSERT(turn != 0.0);/// TODO : Straight curves?
   
   Orient o = start.orient;
   Vec3 pos = start.pos;
   
   Vec3 fw = o.Fw();
   Vec3 up = o.Up();
   Vec3 rt = o.Rt();
   
   up = Rotate3D(up , fw , roll);
   rt = Rotate3D(rt , fw , roll);

   const double radius = length/fabs(turn);

   Vec3 rad = rt*radius*((turn < 0.0)?-1.0:1.0);
   Vec3 c = pos + rad;
   
   rad = Rotate3D(-rad , up , turn*pct);
   
   Vec3 pos2 = c + rad;

   const double yaw = turn*pct*cos(roll);
   const double pitch = turn*pct*sin(roll);

   o.TurnLocal(Vec3(yaw,-pitch,0.0) , 1.0);
   
   return SpatialInfo(pos2 , o);
}




