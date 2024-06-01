



#ifndef Scene_HPP
#define Scene_HPP


#include "Eagle/Events.hpp"


enum STATUS {
   STATUS_OK   = 0,
   STATUS_QUIT = 1
};





class EagleGraphicsContext;

class Scene {
public :
   virtual ~Scene() {}
   
   virtual STATUS HandleEvent(EagleEvent ev)=0;
   virtual void Display(EagleGraphicsContext* win)=0;
   virtual STATUS Update(double dt)=0;
};


#endif // Scene_HPP

