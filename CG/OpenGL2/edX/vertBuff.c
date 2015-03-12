#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>

	GLfloat vertices[4][3]={
		{0.0,0.0,0.0},{0.0,1.0,0.0},{1.0,1.0,0.0},{1.0,0.0,0.0}
		};
	GLfloat colors[4][3]={
		{0.0,0.0,0.0},{0.0,1.0,0.0},{1.0,0.0,0.0},{1.0,0.0,0.0}
		};
	GLubyte indices[1][4]={
		{0,1,2,3}
		};

	const int numObjects=1;
	const int bufPerObject=3;
	
	GLuint buffers[3];
	GLuint objects[1];
	GLenum primitiveType[1];
	GLsizei NumElements[1];
	
	#define BUFFER_OFFSET(bytes) ((GLubyte *)NULL +(bytes))
	#define NumberOf(array) (sizeof(array)/sizeof(array[0]))
	
	enum {Vertices,Colors,Elements};
	enum{Plane};


int winX = 500;  /* length of a side of the monitor window */
int winY=500;  /* length of a side of the monitor window */

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
	
	
	
	
	glFlush();                       /* send all commands */
	usleep(100000);
	glutPostRedisplay();
}
void initObject(GLuint object, GLfloat *vert, GLint sizeVert, GLfloat *col, GLint sizeCol, GLubyte *inds, GLint sizeind, GLenum type){
	
	int offset = object + bufPerObject; 
	glBindBuffer(GL_ARRAY_BUFFER, buffers[Vertices+offset]);
	glBufferData(GL_ARRAY_BUFFER,sizeVert,vert, GL_STATIC_DRAW);
	
	
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
