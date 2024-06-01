



#ifndef Skybox_HPP
#define Skybox_HPP


#include "UnitCube.hpp"

#include "allegro5/allegro.h"
#include "allegro5/allegro_opengl.h"

#include "BasicGLSetup.hpp"

#include "GL/gl.h"
#include "GL/glu.h"


class Skybox {
   
   TexturedUnitCube sbcube;
   
   ALLEGRO_BITMAP* sbimage;
   ALLEGRO_BITMAP* sbfaces[NUM_CUBE_FACES];
   
   void Clear();

   void MakeSkybox(const char* skybox_file);
   
public :
   Skybox(const char* skybox_file);
   ~Skybox() {Clear();}
   
   void Render(Vec3 pos);
};

#endif // Skybox_HPP



