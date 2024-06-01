



#include "BasicGLSetup.hpp"
#include "allegro5/allegro_opengl.h"

#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glext.h"

#include <cstdio>


double FPS = 60.0;
double SPT = 1.0/FPS;

unsigned int errcount = 0;

unsigned int ErrCount() {return errcount;}

int begin_count = 0;

void eglBegin(GLenum mode) {
   begin_count++;
   if (begin_count > 1) {
      printf("Too many glBegin calls!\n");
   }
   glBegin(mode);
}

void eglEnd() {
   begin_count--;
   if (begin_count > 0) {
      printf("Unclosed glBegin!\n");
   }
   glEnd();
}



#include <cstdio>
#include <map>

std::map<unsigned int , int> errmap;

void __stdcall
MessageCallback( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLbyte* message,
                 const void* userParam )
{
   unsigned int err = glGetError();
//   fprintf( stdout, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
//           ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
//            type, severity, message );
//   fprintf(stdout , "glGetError reports error %lu\n" , glGetError());
   errmap[err]++;
   errcount++;
}

bool BasicGLSetup() {
   // During init, enable debug output
   glEnable              ( GL_DEBUG_OUTPUT );
   glDebugMessageCallback( (GLDEBUGPROC)MessageCallback, 0 );

   if (!CheckOpenGL()) {
      return false;
   }
   return true;
}

void DumpErrors() {
   for (std::map<unsigned int , int>::iterator it = errmap.begin() ; it != errmap.end() ; ++it) {
      printf("%d errors of type %u\n" , it->second , it->first);
   }
}





bool CheckOpenGL() {
   return glGenBuffers && glBindBuffer && glBufferData && glCreateShader && glCreateProgram && glShaderSource;
}
