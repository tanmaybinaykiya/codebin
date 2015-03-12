#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

const int   A = 500;  /* length of a side of the monitor window */
const float B = 500;  /* length of a side of the clipping rectangle */
const float C = 200;  /* length of a side of the square the program draws */

void myinit(void)
{
	glClearColor(0.8, 0.8, 0.8, 0.0); /* gray background */
	glMatrixMode(GL_PROJECTION);      /* In World coordinates: */
	glLoadIdentity();                 /* position the "clipping rectangle" */
	//gluOrtho2D(-B/2, B/2, -B/2, B/2);/* at -B/2, its right edge at +B/2, its bottom */
	glMatrixMode(GL_MODELVIEW);       /* edge at -B/2 and its top edge at +B/2 */
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
	glMatrixMode(GL_MODELVIEW);       /* The following coordinates are expressed */
	glLoadIdentity();                 /* in terms of World coordinates */

	printf("\n GL MODELVIEW ");
	printV(GL_MODELVIEW_MATRIX);
	printf("\n GL PROJECTION ");
	printV(GL_PROJECTION_MATRIX);
	glTranslatef(.5,0,0);
	glRotatef(10,1,1,0);
	printf("\n GL MODELVIEW ");
	printV(GL_MODELVIEW_MATRIX);
	
	glutWireSphere(0.5,10,10);
	glFlush();                       /* send all commands */
}

void keyHandle(unsigned char key,int x, int y){

	if (key==27){
		exit(0);
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc,argv);                                   /*initialize the toolkit   */
	glutInitWindowSize( 500, 500 );                         /* Set window size */
	glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE);           /* Set the display mode */
	glutInitWindowPosition( 100, 100 );  
	glutCreateWindow("My Points");                          /* create window with title */
	glutDisplayFunc(display);                               /*tell OpenGL main loop what     */
	myinit();												/* set attributes                 */
	glutKeyboardFunc(keyHandle);
	glutMainLoop();                                         /* pass control to the main loop  */
	return 1;
}
