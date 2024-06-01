/**
My entry for TINS 2024. Copyright Edgar Reynaldo, 2024+

Rules are :
1. Trains
2. Art Nouveau
3. Customization
4. Quadratic formula
5. Cool story, bro

I'll be using racing trains you can customize and I'm too short on time to do art nouveau properly so I'm using cool story bro to get rid of it.
You'll note I made it part of the name just to do it anyway.

*/

#include "Eagle.hpp"
#include "Eagle/backends/Allegro5Backend.hpp"
#include "allegro5/allegro.h"
#include "allegro5/allegro_opengl.h"
#include "GL/gl.h"

#include "Scene.hpp"
#include "Editor.hpp"

int main(int argc , char** argv) {

   (void)argc;
   (void)argv;

   


   Allegro5System* sys = GetAllegro5System();
   EAGLE_ASSERT(sys);

   int ret = sys->Initialize(EAGLE_FULL_SETUP);
   if (ret != EAGLE_FULL_SETUP) {
      EagleWarn() << PrintFailedEagleInitStates(EAGLE_FULL_SETUP , ret) << std::endl;
   }
//   EAGLE_ASSERT(ret == EAGLE_FULL_SETUP);
   
   // our windowed fallback size
   int scrw = 1280;
   int scrh = 800;

   Allegro5GraphicsContext* win = dynamic_cast<Allegro5GraphicsContext*>(sys->CreateGraphicsContext("TrainKart" , scrw , scrh , EAGLE_OPENGL | EAGLE_FULLSCREEN_WINDOW));

   EAGLE_ASSERT(win);

   win->Clear(EagleColor(255,255,255,255));

   win->FlipDisplay();

   bool ok = BasicGLSetup();
   EAGLE_ASSERT(ok);

   EagleFont* afont = win->GetFont("Data/Fonts/Orangerie.otf" , -48);

   Editor e;
   Editor* editor = &e;
   
   bool quit = false;
   bool redraw = true;
   
   sys->GetSystemTimer()->Start();
   
   while (!quit) {
      
      if (redraw) {
         win->Clear();
         editor->Display(win);
         win->FlipDisplay();
         redraw = false;
      }
      
      do {
         EagleEvent e = sys->WaitForSystemEventAndUpdateState();
         
         if (e.type == EAGLE_EVENT_DISPLAY_CLOSE) {quit = true;break;}
         if (e.type == EAGLE_EVENT_KEY_DOWN && e.keyboard.keycode == EAGLE_KEY_ESCAPE) {quit = true;}
         if (e.type == EAGLE_EVENT_TIMER) {
            redraw = true;
            editor->Update(e.timer.eagle_timer_source->SPT());
         }
         else {
            int status = editor->HandleEvent(e);
            if (status == STATUS_QUIT) {
               quit = true;
            }
         }
         
      } while (!sys->UpToDate());
   }

   return 0;
}
