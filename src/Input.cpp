



#include "Input.hpp"


/** KEYBOARD */

bool keys[ALLEGRO_KEY_MAX] = {0};

/** MOUSE */

int mx = 0;
int my = 0;

bool mbtns[8] = {false};



/** INPUT ROUTINES */



void HandleInputEvent(ALLEGRO_EVENT ev) {
   if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
      keys[ev.keyboard.keycode] = true;
   }
   if (ev.type == ALLEGRO_EVENT_KEY_UP) {
      keys[ev.keyboard.keycode] = false;
   }
   if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
      mx = ev.mouse.x;
      my = ev.mouse.y;
      int btn = ev.mouse.button;
      if (btn == 2) {
         btn = 3;
      }
      else if (btn == 3) {
         btn = 2;
      }
      mbtns[btn - 1] = true;
   }
   if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
      mx = ev.mouse.x;
      my = ev.mouse.y;
      int btn = ev.mouse.button;
      if (btn == 2) {
         btn = 3;
      }
      else if (btn == 3) {
         btn = 2;
      }
      mbtns[btn - 1] = false;
   }
   if (ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
      mx = ev.mouse.x;
      my = ev.mouse.y;
   }
}



