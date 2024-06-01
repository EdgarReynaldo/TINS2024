



#ifndef Input_HPP
#define Input_HPP





#include "allegro5/allegro.h"

/** KEYBOARD DATA */

extern bool keys[ALLEGRO_KEY_MAX];


/** MOUSE DATA */


enum MBTN {
   LMB = 0,
   MMB = 1,
   RMB = 2,
   EMB1 = 3,
   EMB2 = 4,
   EMB3 = 5,
   EMB4 = 6,
   EMB5 = 7
};

extern int mx;
extern int my;

extern bool mbtns[8];

/** INPUT ROUTINES */


void HandleInputEvent(ALLEGRO_EVENT ev);



#endif // Input_HPP

