#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>

int qElb=90,qSho=0,qFing=0, flagElb=1;
float cubeSize=0.5,lSho=4,lFing=0.6, lArm=3;

void myinit(void)
{
	glClearColor(0.2, 0.2, 0.2, 0.0); /* gray background */
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat mat_shininess[] = { 5.0 };
	GLfloat light_position[] = { 5.0,0.8,5.0,1.0 };
	//glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	
	
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
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    /*clear the window */
	glColor3f(1,1,1);
	/* ********************************************************SHO*/
	glPushMatrix();

	glPushMatrix();
	glScalef(1,lSho,0.5);
	glutSolidCube(cubeSize);
/* ********************************************************ARM*/	
	glPopMatrix();
	float off=(lSho+lArm)*(cubeSize/4);
	//printf("ang =%f\n",ang);
	glTranslatef(0,off+0.12,0);
	glRotatef(qElb,1,0,0);
	glTranslatef(0,off-0.12,0);
	glPushMatrix();
	glScalef(1,lArm,0.5);
	glutSolidCube(cubeSize);
/* ********************************************************FINGERS*/
	glPopMatrix();
	float off2=(lFing+lArm)*(cubeSize/4);
	//printf("ang =%f\n",ang);
	glTranslatef(0,off2+0.3,0);
	glRotatef(qFing,1,0,0);
	glTranslatef(0,off2-0.3,0);
	glPushMatrix();
	glScalef(0.1,lFing,0.1);
	glutSolidCube(cubeSize);
	glTranslatef(1.1,0,0);
	glutSolidCube(cubeSize);
	glTranslatef(-2.2,0,0);
	glutSolidCube(cubeSize);
	glTranslatef(-1.1,0,0);
	glutSolidCube(cubeSize);

	glPopMatrix();
	glPopMatrix();
	
	glFlush();
	
	qElb=(qElb+3)%45;
//	qSho=(qSho+6)%90;
	qFing=(qFing+6)%90;
	
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
	gluLookAt (5.0, 0, 5.0, 0.0, 0.8, 0.0, -1.0, 0.0, 0.0);
	}
int main(int argc, char** argv)
{
	glutInit(&argc,argv);									//initialize the toolkit
	glutInitWindowSize( 500,500 );							// Set window size
	glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE);			// Set the display mode
	glutInitWindowPosition( 100, 100 );  
	glutCreateWindow("Robotic Arm");							// create window with title
	glutDisplayFunc(display);								//tell OpenGL main loop what
	myinit();												// set attributes
	glutKeyboardFunc(keyHandle);
	glutReshapeFunc(reshape);
	glutMainLoop();											// pass control to the main loop  
//	glutIdleFunc(display);
	return 1;
}
