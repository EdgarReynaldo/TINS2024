



#include "Intro.hpp"
#include "allegro5/allegro.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_color.h"


#include "BasicAllegro.hpp"



void Intro() {
   al_flush_event_queue(q);
   
   al_clear_to_color(al_map_rgb(0,255,0));
   
   int fh = 78;
   ALLEGRO_FONT* f2 = al_load_ttf_font("Verdana.ttf" , fh , 0);

   int j = 0;

   al_start_timer(timer);
   
   for (float s = 0.01 ; s <= 1.0 ; s += 0.01) {
      if (!f2) {continue;}
      
      al_clear_to_color(al_map_rgb(0,0,0));
      
      ALLEGRO_TRANSFORM tr;
      al_identity_transform(&tr);
      al_translate_transform(&tr , -sw/2 , -sh/2);
      al_scale_transform(&tr , s , s);
      al_translate_transform(&tr , sw/2 , sh/2);
      al_use_transform(&tr);
      ALLEGRO_COLOR c = al_color_hsv(j*3 , 1.0 , 1.0);
      al_draw_textf(f2 , c , sw/2 + 2 , sh/2 - fh - 10 , ALLEGRO_ALIGN_CENTER , "Hello Krampus xD");
      al_draw_textf(f2 , c , sw/2 + 2 , sh/2 + 10 , ALLEGRO_ALIGN_CENTER , "Holly Hack 2018!");
      al_flip_display();
      ALLEGRO_EVENT ev2;
      do {
         al_wait_for_event(q , &ev2);
      } while (ev2.type != ALLEGRO_EVENT_TIMER);
      ++j;
   }
   al_destroy_font(f2);
}
