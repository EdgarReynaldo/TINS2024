



#ifndef BasicGLSetup_HPP
#define BasicGLSetup_HPP

#include "GL/gl.h"
#ifndef GL_CLAMP_TO_EDGE 
   #define GL_CLAMP_TO_EDGE 0x812F
#endif

extern double FPS;
extern double SPT;

bool BasicGLSetup();

bool CheckOpenGL();

unsigned int ErrCount();

void DumpErrors();

void eglBegin(GLenum mode);
void eglEnd();

#endif // BasicAllegro_HPP




