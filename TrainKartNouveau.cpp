
/**
My entry for TINS 2024.

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












int main(int argc , char** argv) {

   (void)argc;
   (void)argv;

   Allegro5System* sys = GetAllegro5System();
   EAGLE_ASSERT(sys);

   // our windowed fallback size
   int scrw = 1280;
   int scrh = 800;

   Allegro5GraphicsContext* win = dynamic_cast<Allegro5GraphicsContext*>(sys->CreateGraphicsContext(scrw , scrh , EAGLE_OPENGL | EAGLE_FULLSCREEN_WINDOW));

   EAGLE_ASSERT(win);

   win->Clear(EagleColor(255,255,255,255));

   win->FlipDisplay();

   bool ok = BasicGLSetup();
   EAGLE_ASSERT(ok);










   sys->Rest(3.0);

   return 0;
}
