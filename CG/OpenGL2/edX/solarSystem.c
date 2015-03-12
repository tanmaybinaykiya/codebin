#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>

float   ROT = 50;  /* length of a side of the monitor window */
const float B = 5;  /* length of a side of the clipping rectangle */

void myinit(void)
{
	glClearColor(0.2, 0.2, 0.2, 0.0); /* gray background */
	//glMatrixMode(GL_PROJECTION);      /* In World coordinates: */
	//glLoadIdentity();                 /* position the "clipping rectangle" */
	//gluOrtho2D(-B/2, B/2, -B/2, B/2);/* at -B/2, its right edge at +B/2, its bottom */
	//glFrustum(-10,10,-10,10,2,7);
	//gluLookAt(-4,0,4,-4,0,0,0, 1, 0 );
	glMatrixMode(GL_MODELVIEW);       /* edge at -B/2 and its top edge at +B/2 */
	glLoadIdentity();                 /* in terms of World coordinates */
	
}
void printV(int a){
	GLfloat mod[4][4]={0.0};
	glGetFloatv(a,*mod);
	int i,j;
	printf("MATRIX: \n");
	printf("======================\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			printf("%3.2f ",mod[j][i]);
		printf("\n");
	}
}
void display( void )
{
	glClear(GL_COLOR_BUFFER_BIT);     /*clear the window */
//	glCullFace(0);
	printf("Entered Display \n");
	printV(GL_MODELVIEW_MATRIX);
	glRotatef(5,0,0,1);

	glPushMatrix();
	glColor3f(1,1,0);
	glutWireSphere(1.0, 20, 16);
	/* draw sun */
	glRotatef (6, 0.0, 1.0, 0.0);

	glTranslatef (2.0, 0.0, 0.0);
	glColor3f(0,0,1);
	
	glutWireSphere(0.2, 10, 8);
	/* draw smaller planet */
	glPopMatrix();
	glutSwapBuffers();

	glFlush();                       /* send all commands */
	usleep(100000);
	glutPostRedisplay();
}

void keyHandle(unsigned char key,int x, int y){

	if (key==27){
		exit(0);
	}
}
void reshape(int w,int h){
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt (5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
	}
int main(int argc, char** argv)
{
	glutInit(&argc,argv);									//initialize the toolkit
	glutInitWindowSize( 500,500 );							// Set window size
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
