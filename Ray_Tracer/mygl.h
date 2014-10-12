#ifndef __RAGIB_GL_HEADER__
#define __RAGIB_GL_HEADER__

#if defined(_WIN32) || defined(WIN32) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__BORLANDC__)
    #define __WIN32
    #include<windows.h>
#endif

#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif


#endif
