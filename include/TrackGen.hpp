



#ifndef TrackGen_HPP
#define TrackGen_HPP


#include "SpatialInfo.hpp"



class StraightAway {
protected :
   double l;
public :
   StraightAway(double length) : l(fabs(length)) {}
   
   SpatialInfo Eval(const SpatialInfo& start , double pct);
   
   double Length() {return l;}
};


/**
   A turn is a change in yaw, relative to the local axis
*/
class Turn {

double w,h,l;
   
   double CalcLength();
   
public :
   
   Turn(double width , double height) : w(width) , h(fabs(height)) , l(CalcLength()) {}
   
   
   SpatialInfo Eval(const SpatialInfo& start , double pct);
   double Length() {return l;}

};

class CurvedTrack {
   
   double length;
   double turn;
   double roll;
   
public :   
///   CurvedTrack(double turn_angle , double roll_angle , double track_length);
   CurvedTrack(double turn_angle , double roll_angle , double track_length) :
         length(abs(track_length)),
         turn(turn_angle),
         roll(roll_angle)
   {}
   
   
   SpatialInfo Eval(const SpatialInfo& start , double pct);
   double Length() {return length;}
};




#endif // TrackGen_HPP

