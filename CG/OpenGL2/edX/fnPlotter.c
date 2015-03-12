#include<stdio.h>
#include<stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
static int shoulder = 0, elbow = 0;
void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
}
void initialize(GLfloat*** vertArr)
{
	int i,j,k;
	for(k=0;k<4;k++){
		for(i=0;i<4;i++){
			for(j=0;j<3;j++){
					if(j==2)
						(vertArr[k][i][j])=(i+1);					//z
					if(j==1){												//y axis
						if(k==0||k==3){
						(vertArr[k][i][j])=(1);
							}
						else{
							(vertArr[k][i][j])=0;
							}	
					}
					if(j==0){												//x axis
						(vertArr[k][i][j])=i;
					}
			}
		}
	}
}

void  showArr(GLfloat*** vertArr){
	int i,j,k;
	for(k=0;k<4;k++){
		for(i=0;i<4;i++){
			for(j=0;j<3;j++){
			printf("%4.2f ",vertArr[k][i][j]);
			}
			printf("\t");
		}
		printf("\n");
	}
}
void display(void)
	{
	GLfloat*** vertArr;
	GLfloat vertices[20][3]={
								{0,1,0},{0,1,-1},{1,0,0},{1,0,-1},{2,0,0},{2,0,-1},{3,0,0},{3,0,-1},{4,1,0},{4,1,-1},

								{0,1,-2},{0,1,-3},{1,0,-2},{1,0,-3},{2,0,-2},{2,0,-3},{3,0,-2},{3,0,-3},{4,1,-2},{4,1,-3}
							};
	
	vertArr=vertices;
	
	//~ int i,j,k;
	//~ vertArr=(float *)malloc(4*(sizeof(float)));
	//~ 
	//~ for(i=0;i<4;i++){
		//~ vertArr[i]=(float *)malloc(4*(sizeof(float)));
	//~ }
	//~ for(i=0;i<4;i++){
		//~ for(j=0;j<4;j++){
		//~ vertArr[i][j]=(float *)malloc(3*(sizeof(float)));
		//~ }
	//~ }

	initialize(vertArr);
	showArr(vertArr);
	
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,0);
	
	glBegin(GL_TRIANGLE_STRIP);
	glEnd();
	glutSwapBuffers();
}

void keyboard (unsigned char key, int x, int y)
{
	switch (key) {
		case 27:
			exit(0);
			break;
	}
}
void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 1000.0);
	gluLookAt(0,0,10,0,0,0,0,1,0);
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	glTranslatef(-5,-2,-10);
	//~ glScalef(.2,0.2,0.2);
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
