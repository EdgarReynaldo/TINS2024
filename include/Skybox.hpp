



#ifndef Skybox_HPP
#define Skybox_HPP


#include "Cube.hpp"
#include "allegro5/allegro.h"
#include "allegro5/allegro_opengl.h"


#include "Cube.hpp"

#include "GL/gl.h"
#include "GL/glu.h"

#define GL_CLAMP_TO_EDGE 0x812F

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



