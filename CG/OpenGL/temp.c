#include <GL/glu.h>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>

const int   X = 200;  /* length of a side of the monitor window */
const int   Y = 200;
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
  int x,y,R,h,dE,dSE;
  x=0;
  R=100;
  y=R;
  h=1-R;
  dE=3;
  dSE = -2*R+5;
  glBegin(GL_POINTS) ;              /* draw a filled polygon */
  glColor3f ( 0.0, 0.0,0.0);   /* draw in light red */

  glVertex2i(X+x,X+y);
  glVertex2i(X-x,X+y);
  glVertex2i(X-x,X-y);
  glVertex2i(X+x,X-y);

  glVertex2i(X+y,X+x);
  glVertex2i(X-y,X+x);
  glVertex2i(X-y,X-x);
  glVertex2i(X+y,X-x);
    glEnd();
  while(y>x)
  	{
  		if(h<0)
  		{
  			h=h+dE;
  			dE=dE+2;
  			dSE=dSE+2;
  		}
        else
        {
        	h=h+dSE;
        	dE=dE+2;
        	dSE=dSE+4;
        	y--;
        }
        x++;
        glBegin(GL_POINTS) ;              /* draw a filled polygon */
		glColor3f ( 0.0, 0.0,0.0);   /* draw in light red */

  glVertex2i(X+x,Y+y);
  glVertex2i(X-x,Y+y);
  glVertex2i(X-x,Y-y);
  glVertex2i(X+x,Y-y);

  glVertex2i(X+y,Y+x);
  glVertex2i(X-y,Y+x);
  glVertex2i(X-y,Y-x);
  glVertex2i(X+y,Y-x);
    glEnd();   
    }  


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
