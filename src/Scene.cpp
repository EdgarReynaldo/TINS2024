



#include "Scene.hpp"
#include "Input.hpp"



STATUS Scene::HandleEvent(ALLEGRO_EVENT ev) {

   HandleInputEvent(ev);

   if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
      return STATUS_QUIT;
   }
   if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
      return STATUS_QUIT;
   }

   return STATUS_OK;
}
