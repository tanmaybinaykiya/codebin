#include <GL/glu.h>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

const int   X = 200;  /* length of a side of the monitor window */
const int   Y = 200;
void myinit(void)
{
  glClearColor(01, 01, 01, 0.0); /* gray background */

  glMatrixMode(GL_PROJECTION);      /* In World coordinates: */
  glLoadIdentity();                 /* position the "clipping rectangle" */

  gluOrtho2D(-100,200,-100,200); /* at -B/2, its right edge at +B/2, its bottom */
  glMatrixMode(GL_MODELVIEW);       /* edge at -B/2 and its top edge at +B/2 */
}

void display( void )
{
  glClear(GL_COLOR_BUFFER_BIT);     /*clear the window */
 
  glMatrixMode(GL_MODELVIEW);       /* The following coordinates are expressed */
  glLoadIdentity();                 /* in terms of World coordinates */
  int i;	
		float pi=3.14;
  int p1[][2]={{0,0},{20,0},{20,20},{0,20},{0,0},{0,20},{10,30},{20,20}};
  int M3[3][3]={{1,0,1},{0,1,-3},{0,0,1}};
  int M2[3][3]={{cos(pi/2),-sin(pi/2),0},{sin(pi/2),cos(pi/2),0},{0,0,1}};
  int M1[3][3]={{2,0,0},{0,1,0},{0,0,1}};
  int M[3][3]={0};
  glBegin(GL_POLYGON) ;              /* draw a filled polygon */
	  glColor3f ( 0.0, 0.0,0.0);   /* draw in light red */
	/*	for(i=0;i<=7;i++)
	  glVertex2i(90+0,90+0);	
	  glVertex2i(90+0,90+20);	

	  glVertex2i(90+00,90+20);	
	  glVertex2i(90+10,90+30);	

	  glVertex2i(90+10,90+30);	
	  glVertex2i(90+20,90+20);	

	  glVertex2i(90+20,90+20);	
	  glVertex2i(90+20,90+0);	

	  glVertex2i(90+0,90+20);	
	  glVertex2i(90+20,90+20);
	
	  glVertex2i(90+0,90+0);	
	  glVertex2i(90+20,90+0);
	 */ 
	for (i=0;i<=7;i++)
	{int x,y;
		//glVertex2iv(p1[i]);
		p1[i][0]=p1[i][0]+10;
		p1[i][1]=p1[i][1]-30;
		x=p1[i][0]*0-p1[i][1]*1;
		y=p1[i][0]*1-p1[i][1]*0;
		p1[i][0]=x;
		pi[i][1]=y;
		p1[i][0]=p1[i][0]*2;
		p1[i][1]=p1[i][1]*1;
		glVertex2iv(p1[i]);
				
	}	
	
/*	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			M[i][j]=
		}
	}
	
*/	
	
	
		
	glEnd();
  glFlush();                        /* send all commands */
  
  
}

int main(int argc, char** argv)
{
  glutInit(&argc,argv);                                   /*initialize the toolkit   */
  glutInitWindowSize( 600, 600 );                         /* Set window size */
  glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE);           /* Set the display mode */
  glutInitWindowPosition(30, 30 );  
  glutCreateWindow("My Points");                          /* create window with title */
  
  glutDisplayFunc(display);                               /*tell OpenGL main loop what     */
  myinit();                                               /* set attributes                 */

  glutMainLoop();                                         /* pass control to the main loop  */
  
  return 1;
}
 








/**/
