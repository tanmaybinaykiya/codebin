#include <GL/glu.h>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>

const int   A = 2500;  /* length of a side of the monitor window */
const float B = 2500;  /* length of a side of the clipping rectangle */
const float C = 200;  /* length of a side of the square the program draws */
void myinit(void)
{
  glClearColor(01, 01, 01, 0.0); /* gray background */

  glMatrixMode(GL_PROJECTION);      /* In World coordinates: */
  glLoadIdentity();                 /* position the "clipping rectangle" */

  gluOrtho2D(0,600,000,780); /* at -B/2, its right edge at +B/2, its bottom */
  glMatrixMode(GL_MODELVIEW);       /* edge at -B/2 and its top edge at +B/2 */
}

void display( void )
{
  glClear(GL_COLOR_BUFFER_BIT);     /*clear the window */
 
  glMatrixMode(GL_MODELVIEW);       /* The following coordinates are expressed */
  glLoadIdentity();                 /* in terms of World coordinates */
  
  int x,y,H,W,
  
  
  
  glVertex2i(250+x,250+y);
  glVertex2i(250-x,250+y);
  glVertex2i(250-x,250-y);
  glVertex2i(250+x,250-y);

  glVertex2i(250+y,250+x);
  glVertex2i(250-y,250+x);
  glVertex2i(250-y,250-x);
  glVertex2i(250+y,250-x);
    glEnd();   
      


  glFlush();                        /* send all commands */
}

int main(int argc, char** argv)
{
  glutInit(&argc,argv);                                   /*initialize the toolkit   */
  glutInitWindowSize( 600, 780 );                         /* Set window size */
  glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE);           /* Set the display mode */
  glutInitWindowPosition(0, 0 );  
  glutCreateWindow("My Points");                          /* create window with title */
  
  glutDisplayFunc(display);                               /*tell OpenGL main loop what     */
  myinit();                                               /* set attributes                 */

  glutMainLoop();                                         /* pass control to the main loop  */
  
  return 1;
}
 








/**/
