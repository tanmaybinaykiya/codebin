#include "structs.h"
#include "catmullclark.c"
_Bool smooth;
void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
}
void showOriginal(){
	int i=0;
	glColor3f(1,1,0);
	for (i=0;i<fIndex ;i++)
	{
		//If the DIAGONALS intersect inside the quad, draw, or swap the edge
		float v1x=vertices[edges[faces[i].edge1].vert1].x;
		float v1y=vertices[edges[faces[i].edge1].vert1].y;
		float v1z=vertices[edges[faces[i].edge1].vert1].z;

		float v2x=vertices[edges[faces[i].edge1].vert2].x;
		float v2y=vertices[edges[faces[i].edge1].vert2].y;
		float v2z=vertices[edges[faces[i].edge1].vert2].z;

		float v3x=vertices[edges[faces[i].edge3].vert1].x;
		float v3y=vertices[edges[faces[i].edge3].vert1].y;
		float v3z=vertices[edges[faces[i].edge3].vert1].z;

		float v4x=vertices[edges[faces[i].edge3].vert2].x;
		float v4y=vertices[edges[faces[i].edge3].vert2].y;
		float v4z=vertices[edges[faces[i].edge3].vert2].z;

		printf("\nBefore setting t \n");
		printf("vx %4.2f, vy %4.2f, vz %4.2f, ax %4.2f,bx %4.2f,cz %4.2f \n",v1x,v1y,v1z,v2x,v2y,v2z);
		printf("vx %4.2f, vy %4.2f, vz %4.2f, ax %4.2f,bx %4.2f,cz %4.2f \n ",v3x,v3y,v3z,v4x,v4y,v4z);

		int parallel=1;

		float tx;
		if(v1x!=v4x){
			tx=(v2x-v3x)/(v1x-v4x);
			if(tx!=-1)
			{
				tx=tx/(1+tx);
			}
			else{
				parallel*=-1;
			}
		}
		else{
			tx=-1;
			parallel*=-1;
		}
		float ty;
		if(v1y!=v4y){
			tx=(v2y-v3y)/(v1y-v4y);
			if(ty!=-1)
			{
				ty=ty/(1+ty);
			}
			else{
				parallel*=-1;
			}
		}
		else{
			ty=-1;
			parallel*=-1;
		}
		
		float tz;
		if(v1z!=v4z){
			tx=(v2z-v3z)/(v1z-v4z);
			if(tz!=-1)
			{
				tz=tz/(1+tz);
			}
			else{
				parallel*=-1;
			}
		}
		else{
			tz=-1;
			parallel*=-1;
		}
		printf("\nT : tx %f, ty %f, tz %f \n",tx,ty,tz);
		glColor3f(1-(float)i/5,1-(float)i/5,0);
		glBegin(GL_POLYGON);
		if ((parallel==-1)||((0<=tx && tx<1) && (0<=ty && ty<1) && (0<=tz && tz<1)))
			{
				printf("\n  t between 0 and 1 \n");
				//~ printf("vx %f, vy %f, vz %f, ax %f,bx %f,cx %f \n",v1x,v1y,v1z,v2x,v2y,v2z);
				//~ printf("vx %f, vy %f, vz %f, ax %f,bx %f,cx %f \n ",v3x,v3y,v3z,v4x,v4y,v4z);
				glVertex3f(v1x,v1y,v1z);
				glVertex3f(v2x,v2y,v2z);
				glVertex3f(v4x,v4y,v4z);
				glVertex3f(v3x,v3y,v3z);
				glVertex3f(v1x,v1y,v1z);
			}
			else{ 
				printf("\n \t Outside 0 and 1 \n");
				//~ printf("\t vx %f, vy %f, vz %f, ax %f,bx %f,cx %f \n",v1x,v1y,v1z,v2x,v2y,v2z);
				//~ printf("\t vx %f, vy %f, vz %f, ax %f,bx %f,cx %f \n ",v3x,v3y,v3z,v4x,v4y,v4z);
				//~ printf("\n -------------\n");
				glVertex3f(v1x,v1y,v1z);
				glVertex3f(v2x,v2y,v2z);
				glVertex3f(v3x,v3y,v3z);
				glVertex3f(v4x,v4y,v4z);
				glVertex3f(v1x,v1y,v1z);
			}
		glEnd();
	}
}
void showAxis(){
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex3f(0,0,0);
		glVertex3f(10,0,0);
		glVertex3f(0,0,0);
		glVertex3f( 0,10,0);
		glVertex3f(0,0,0);
		glVertex3f(0,0,10);
	glEnd();
} 
void display(void){
	int i;
	glClear (GL_COLOR_BUFFER_BIT);
	glRotatef(1,0,1,0.1);
	showAxis();
	
	if (!smooth){
		showOriginal();
	}
	else {
		showSubdiv();
	}

	glutSwapBuffers();
	usleep(1000);
	glutPostRedisplay();
}

void keyboard (unsigned char key, int x, int y)
{
	switch (key) {
		case 27:
			exit(0);
			break;
		case 'n':
			smooth=!smooth;
			glutPostRedisplay();
			break;
	}
}
void reshape (int w, int h)
{
	glViewport (0,0,(GLsizei) w,(GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 1000.0);
	gluLookAt(0,5,5,0,0,0,0,1,0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();
	input();
	subdivide();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
