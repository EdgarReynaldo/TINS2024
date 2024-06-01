



#ifndef BasicGLSetup_HPP
#define BasicGLSetup_HPP


extern double FPS;
extern double SPT;

bool BasicGLSetup();

bool CheckOpenGL();

unsigned int ErrCount();

void DumpErrors();

void eglBegin(GLenum mode);
void eglEnd();

#endif // BasicAllegro_HPP




