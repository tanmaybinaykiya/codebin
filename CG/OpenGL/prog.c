
#include<stdlib.h>
#include<GL/glut.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,0.0);

	glBegin(GL_LINES);
		glVertex2f(10.0,10.0);
		glVertex2f(150.0,80.0);
		glVertex2f(100.0,20.0);
		glVertex2f(200.0,100.0);
	glEnd();
	glFlush();
}

void myinit()
{
	glClearColor(0.0,1.0,1.0,1.0);
	glPointSize(10.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(.0,50.0,.0,50.0);
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(300,200);
	glutInitWindowPosition(0,700);

	glutCreateWindow("points");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
	return 0;
}


