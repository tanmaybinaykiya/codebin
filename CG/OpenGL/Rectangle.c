#include <GL/glu.h>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#define X .525731112119133606
#define Z .850650808352039932


const int   A = 500;  /* length of a side of the monitor window */
const float B = 500;  /* length of a side of the clipping rectangle */
const float C = 200;  /* length of a side of the square the program draws */

void myinit(void)
{
  glClearColor(01, 01, 01, 0.0); /* gray background */

  glMatrixMode(GL_PROJECTION);      /* In World coordinates: */
  glLoadIdentity();                 /* position the "clipping rectangle" */

  gluOrtho2D(0,500,000,400); /* at -B/2, its right edge at +B/2, its bottom */
  glMatrixMode(GL_MODELVIEW);       /* edge at -B/2 and its top edge at +B/2 */
}

void display( void )
{
  glClear(GL_COLOR_BUFFER_BIT);     /*clear the window */
 
  glMatrixMode(GL_MODELVIEW);       /* The following coordinates are expressed */
  glLoadIdentity();                 /* in terms of World coordinates */

  glBegin(GL_LINES) ;              /* draw a filled polygon */
    glRecti(50,100,200,150);
//      glColor4f ( 0.0, 0.0,0.0,0.0);   /* draw in light red */
//      glVertex2i( 100, 100 );         /* (x,y) */
//      glVertex2i( 205, 205 );         /* (x,y) */
//      glVertex2i( 100, 150 );         /* (x,y) */
//      glVertex2i( 150, 100 );         /* (x,y) */
      
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
