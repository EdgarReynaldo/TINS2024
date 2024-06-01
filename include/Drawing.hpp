



#ifndef Drawing_HPP
#define Drawing_HPP

#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"



#include "Vec3.hpp"
#include "Prism.hpp"
#include "Track.hpp"

#include "allegro5/allegro.h"
#include "GL/gl.h"
#include "BasicGLSetup.hpp"

/** Not thread safe */
inline void DrawLine(const Vec3& p1 , const Vec3& p2 , EagleColor c) {
   
   eglBegin(GL_LINES);
   glColor4ub(c.r , c.g , c.b , c.a);
   glVertex3d(p1.x , p1.y , p1.z);
   glVertex3d(p2.x , p2.y , p2.z);
   eglEnd();
   
}

void OutlinePrism(const Prism& p , EagleColor c);


void DrawTrackOutlines(const Track& track);


#endif // Drawing_HPP
