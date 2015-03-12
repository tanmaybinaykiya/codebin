#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#define X .525731112119133606
#define Z .850650808352039932

float   ROT = 50;  /* length of a side of the monitor window */
int winX = 500;  /* length of a side of the monitor window */
int winY=500;  /* length of a side of the monitor window */
const float B = 5;  /* length of a side of the clipping rectangle */
const float C = 200;  /* length of a side of the square the program draws */

void myinit(void)
{
	glClearColor(0.8, 0.8, 0.8, 0.0); /* gray background */
	glMatrixMode(GL_PROJECTION);      /* In World coordinates: */
	glLoadIdentity();                 /* position the "clipping rectangle" */
	//gluOrtho2D(-B/2, B/2, -B/2, B/2);/* at -B/2, its right edge at +B/2, its bottom */
	glFrustum(-2,2,-2,2,5,10);
		gluLookAt(0,0,-5, 0,0,0,0, 1, 0 );
	glMatrixMode(GL_MODELVIEW);       /* edge at -B/2 and its top edge at +B/2 */
	glLoadIdentity();                 /* in terms of World coordinates */
	
}
void display( void )
{
	glClear(GL_COLOR_BUFFER_BIT);     /*clear the window */
	glCullFace(0);
	glRotatef(5,1,1,1);
	glColor3f(1.0,0,0);
	glBegin(GL_QUADS);
		glNormal3i(0,0,0);			glVertex3i(0,0,0);
		glNormal3i(0,1,0);			glVertex3i(0,1,0);
		glNormal3i(1,1,0);			glVertex3i(1,1,0);          //front
		glNormal3i(1,0,0);			glVertex3i(1,0,0);
		glNormal3i(0,0,0);			glVertex3i(0,0,0);
	glEnd();
	glBegin(GL_QUADS);
		glNormal3i(0,0,1);			glVertex3i(0,0,1);
		glNormal3i(0,1,1);			glVertex3i(0,1,1);
		glNormal3i(1,1,1);			glVertex3i(1,1,1);          //fback
		glNormal3i(1,0,1);			glVertex3i(1,0,1);
		glNormal3i(0,0,1);			glVertex3i(0,0,1);
	glEnd();
	glBegin(GL_LINE_STRIP);
		glNormal3i(0,0,0);			glVertex3i(0,0,0);
		glNormal3i(0,0,1);			glVertex3i(0,0,1);           //bottom
		glNormal3i(1,0,1);			glVertex3i(1,0,1);
		glNormal3i(1,0,0);			glVertex3i(1,0,0);
		glNormal3i(0,0,0);			glVertex3i(0,0,0);
	glEnd();
	glBegin(GL_LINE_STRIP);
		glNormal3i(0,1,0);			glVertex3i(0,1,0);
		glNormal3i(0,1,1);			glVertex3i(0,1,1);           //bottom
		glNormal3i(1,1,1);			glVertex3i(1,1,1);
		glNormal3i(1,1,0);			glVertex3i(1,1,0);
		glNormal3i(0,1,0);			glVertex3i(0,1,0);
	glEnd();
	glBegin(GL_LINE_STRIP);
		glVertex3i(0,0,0);
		glVertex3i(0,0,1);			 //left
		glVertex3i(0,1,1);
		glVertex3i(0,1,0);
		glVertex3i(0,0,0);
	glEnd();
	glBegin(GL_LINE_STRIP);
		glVertex3i(1,0,0);
		glVertex3i(1,0,1);			 //right
		glVertex3i(1,1,1);
		glVertex3i(1,1,0);
		glVertex3i(1,0,0);
	glEnd();
	
	glFlush();                       /* send all commands */
	usleep(100000);
	glutPostRedisplay();
}

void keyHandle(unsigned char key,int x, int y){

	if (key==27){
		exit(0);
	}
}
void reshape(int x,int y){
	
	
	glViewport(0, 0, winX, winY);
	
	
	}
int main(int argc, char** argv)
{
	glutInit(&argc,argv);									//initialize the toolkit
	glutInitWindowSize( winX, winY );							// Set window size
	glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE);			// Set the display mode
	glutInitWindowPosition( 100, 100 );  
	glutCreateWindow("My Points");							// create window with title
	glutDisplayFunc(display);								//tell OpenGL main loop what
	printf("DisplayCallback SET\n");
	myinit();												// set attributes
	printf("INIT CALLED\n");
	glutKeyboardFunc(keyHandle);
	glutReshapeFunc(reshape);
	printf("KEYBOARD SET\n");
	glutMainLoop();											// pass control to the main loop  
	printf("MAINLOOP SET\n");
	glutIdleFunc(display);
	return 1;
}
