



#ifndef Scene_HPP
#define Scene_HPP


#include "allegro5/allegro.h"


enum STATUS {
   STATUS_OK   = 0,
   STATUS_QUIT = 1
};



class Scene {
   
protected :
   bool redraw;
   
public :
   
   Scene() : redraw(true) {}
   virtual ~Scene() {}
   
   
   virtual STATUS HandleEvent(ALLEGRO_EVENT ev)=0;
   virtual void Display()=0;
   virtual STATUS Update(double dt)=0;
   
   inline bool Redraw() {return redraw;}
};


#endif // Scene_HPP

