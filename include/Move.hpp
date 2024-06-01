



#ifndef Move_HPP
#define Move_HPP

#include "Vec3.hpp"



class Move {
   
public :
   Vec3 pos,vel,acc;
   
   void Update(double dt);
   void Update(double dt) {
      pos += vel*dt + acc*0.5*dt*dt;
      vel += acc*dt;
   }
};


#endif // Move_HPP
