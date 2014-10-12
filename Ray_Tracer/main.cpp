
#include "mygl.h"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

#include <ctime>
#include <sys/stat.h>   // For stat().
#include <sys/types.h>  // For stat().

#include "MyMath.h"
#include "Colors.h"
#include "LightSource.h"
#include "SpotLight.h"
#include "Camera.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Square.h"
#include "Check.h"
#include "Checkerboard.h"
#include "World.h"
#include "RayTracer.h"

using namespace std;

#define CAMERA_DIST_THRESH  10
#define DEFAULT_IMAGE_DIMENSION 500

#define UTC (0)
#define BDT (+6)
#define M_PI 3.14


const int WIDTH  = 0;				//output image width
const int HEIGHT = 0;				//output image height

Vector origin = Vector(0, 0, 0);
Vector I = Vector(1, 0, 0);	//X-axis
Vector J = Vector(0, 1, 0);	//Y-axis
Vector K = Vector(0, 0, 1);	//Z-axis

int IMAGE_WIDTH, IMAGE_HEIGHT;
int VIEW_ANGLE = 70;
double CAMERA_DIST;
double projectionDist;

World world;
RayTracer rt;

Triangle *t1;
Square *sq1, *sq2;
Sphere *s1, *s2, *s3, *s4, *s5, *s6, *s7, *s8;
Checkerboard *ck1;
LightSource *ls1, *ls2;

//make a global variable -- for tracking the anglular position of camera
Camera camera(I,-J,K);

bool canDrawGrid;

void design_world();
void design_world1();

bool DirectoryExists( const char* absolutePath ){
    struct stat buffer ;
    return ( !stat( absolutePath, &buffer ) );
}

void Render(string title){
    //Camera cam(camera.front, camera.up, camera.right, (K)*CAMERA_DIST );
	world.setCamera(camera);

    time_t rawtime;
    struct tm * timeinfo;
    struct tm * ptm;
    char buffer [100];

    time ( &rawtime );
    //timeinfo = localtime ( &rawtime );
    ptm = gmtime ( &rawtime );

    strftime (buffer,80,"%Y_%m_%d",ptm);
    sprintf(buffer+strlen(buffer), "_%02d-%02d-%02d",(ptm->tm_hour+BDT)%24, ptm->tm_min, ptm->tm_sec);
    strcat(buffer, "_BDT.bmp");
    int i,len = strlen(buffer);
    for(i=0;i<len;i++)  if(buffer[i] == ':') buffer[i] = '-';

    rt.setWorld(world);
	printf("going to trace ...\n");

	rt.trace(buffer);

	if(!DirectoryExists("images"))  system("mkdir images");

    #if defined(__WIN32)
        system("move *.bmp images");
    #else
        system("mv *.bmp images");
    #endif
}



void display(){

	//clear the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(BLACK, 0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	/********************
	/ set-up camera here
	********************/
	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();

	//now give three info
	//1. where is the camera (viewer)?
	//2. where is the camera is looking?
	//3. Which direction is the camera's UP direction?

	gluLookAt(CO(camera.position),		CO(camera.LookAtPosition()),		CO(camera.up));
	//NOTE: the camera still CONSTANTLY looks at the center
	// cameraAngle is in RADIAN, since you are using inside COS and SIN


	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);


	/****************************
	/ Add your objects from here
	****************************/
	//add objects
	//rotate this rectangle around the Z axis

	int i,k;
	glGetIntegerv(GL_MAX_CLIP_PLANES,&k);
	//printf("%d\n",k);

    glPushMatrix();

        for(i=0;i<world.nObj;i++){
            Object *obj = world.getObject(i);
            obj->glDraw();
        }

        for(i=0;i<world.nL;i++){
            Object *obj = world.getLightSource(i);
            obj->glDraw();
        }

    glPopMatrix();

	//some gridlines along the field
	//int i;

	//WILL draw grid IF the "canDrawGrid" is true:
	if(canDrawGrid == true){
		glColor3f(GRAY);	//grey
		glBegin(GL_LINES);{
			for(i=-10;i<=10;i++){

				if(i==0)
					continue;	//SKIP the MAIN axes

				//lines parallel to Y-axis
				glVertex3f(i*10, -100, 0);
				glVertex3f(i*10,  100, 0);

				//lines parallel to X-axis
				glVertex3f(-100, i*10, 0);
				glVertex3f( 100, i*10, 0);
			}
		}glEnd();
	}

	// draw the two AXES
	glColor3f(WHITE);	//100% white
	glBegin(GL_LINES);{
		//Y axis
		glVertex3f(0, -150, 0);	// intentionally extended to -150 to 150, no big deal
		glVertex3f(0,  150, 0);

		//X axis
		glVertex3f(-150, 0, 0);
		glVertex3f( 150, 0, 0);
	}glEnd();


	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}

void animate(){
	//codes for any changes in Camera

	//codes for any changes in Models

	glutPostRedisplay();	//this will call the display AGAIN
}

void keyboardListener(unsigned char key, int x,int y){
	switch(key){

		case '1':	//reverse the rotation of camera

			break;

		case '2':	//increase rotation of camera by 10%

			break;

		case 'g':	//decrease rotation
            canDrawGrid ^= true;
			break;

		case 'r':	//toggle grids
            Render( "top.bmp" );
			break;

		case 27:	//ESCAPE KEY -- simply exit
			exit(0);
			break;

		default:
			break;
	}
}

void specialKeyListener(int key, int x,int y){
	switch(key){
		case GLUT_KEY_DOWN:		//down arrow key
			if (glutGetModifiers() == GLUT_ACTIVE_SHIFT)   camera.Move(camera.up,-10);
			else    camera.Move(camera.front,-10);
			break;
		case GLUT_KEY_UP:		// up arrow key
            if (glutGetModifiers() == GLUT_ACTIVE_SHIFT)   camera.Move(camera.up,10);
			else    camera.Move(camera.front,10);
			break;

		case GLUT_KEY_RIGHT:
			if (glutGetModifiers() == GLUT_ACTIVE_SHIFT)   camera.Move(camera.right,10);
			else    camera.Turn(10);
			break;
		case GLUT_KEY_LEFT:
			if (glutGetModifiers() == GLUT_ACTIVE_SHIFT)   camera.Move(camera.right,-10);
			else    camera.Turn(-10);
			break;

		case GLUT_KEY_PAGE_UP:
			camera.Pitch(-10);
			break;
		case GLUT_KEY_PAGE_DOWN:
			camera.Pitch(10);
			break;

		case GLUT_KEY_INSERT:
			break;

		case GLUT_KEY_HOME:
			camera.Roll(10);
			break;
		case GLUT_KEY_END:
			camera.Roll(-10);
			break;

		default:
			break;
	}
}

void mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
	switch(button){
		case GLUT_LEFT_BUTTON:

			break;

		case GLUT_RIGHT_BUTTON:
			//........
			break;

		case GLUT_MIDDLE_BUTTON:
			//........
			break;

		default:
			break;
	}
}


void init(){
	//codes for initialization

    projectionDist = IMAGE_HEIGHT/(2*tan( VIEW_ANGLE*M_PI/360 ));
	CAMERA_DIST = CAMERA_DIST_THRESH + projectionDist;

	world = World(I, J, K, 0. );
    design_world();

    rt = RayTracer(world, projectionDist, 4);
    rt.setDimension(IMAGE_WIDTH, IMAGE_HEIGHT);

	canDrawGrid = false;

	camera.front = J;
	camera.up = K;
	camera.right = I;

	camera.position = Vector(CO(Vector((-J)*50)));

	//clear the screen
	glClearColor(BLACK, 0);

	/************************
	/ set-up projection here
	************************/
	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	//give PERSPECTIVE parameters
	gluPerspective(70,	1,	0.1,	10000.0);
	//field of view in the Y (vertically)
	//aspect ratio that determines the field of view in the X direction (horizontally)
	//near distance
	//far distance
}

int main(int argc, char **argv){

    freopen("log.txt","w",stdout);

    if(argc == 1){
		IMAGE_HEIGHT = IMAGE_WIDTH = DEFAULT_IMAGE_DIMENSION;
	}else if(argc == 2){
		IMAGE_HEIGHT = IMAGE_WIDTH = atoi(argv[0]);
	}

	glutInit(&argc,argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("My OpenGL Program");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	//ADD keyboard listeners:
	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);

	//ADD mouse listeners:
	glutMouseFunc(mouseListener);

	glutMainLoop();		//The main loop of OpenGL


	return 0;
}


void design_world(){
    //add light source to world
    ls1 = new LightSource( -I*150-J*100+K*150 , 25., 1.);
    ls1->color = Vector(WHITE);
    ls1->intensity = 0.2;
    world.addLightSource(ls1);

	ls2 = new LightSource( I*150-J*100+K*150 , 25., 1.);
	//ls2 = new LightSource( I*20+K*15 , 10., 1.);
    ls2->color = Vector(WHITE);
    ls2->intensity = 1;
    world.addLightSource(ls2);

    //              origin,     R,   S,  T,  RI, color
    s1 = new Sphere(I*50+J*50-K*15, 20., 0.,  1.,  1.33, Vector(DARKORCHID));
    world.addObject(s1);

    //add another sphere
    s2 = new Sphere(I*40-K*37, 13., 0.6, 0., 1.0, Vector(BLUE));
    //world.addObject(s2);

    //add another sphere
    s3 = new Sphere(-I*10+J*40-K*35,  15., 0.6, 0., 1.0, Vector(GREEN));
    //world.addObject(s3);

    s4 = new Sphere(I*10-J*10-K*42,  8., 0., 0., 1.0, Vector(DEEPSKYBLUE));
    //world.addObject(s4);

    s5 = new Sphere(-J*20-I*20-K*41, 9., 0.6, 0, 1.0, Vector(YELLOW));
    //world.addObject(s5);



    s6 = new Sphere(-J*35+I*35-K*30, 10., 0., 0.8, 1.33, Vector(ORANGE));
    //world.addObject(s6);

    s7 = new Sphere(-I*49.49+J*49.49-K*25, 20., 1., 0.8, 1.33, Vector(RED));
    //world.addObject(s7);

    //s8 = new Sphere(-I*35.35-J*35.35 + K*10, 10., 1., 0., 1., Vector(BLACK));
    s8 = new Sphere(I*49.49 + J*49.49-K*25, 20., 1., 0.8, 1.33, Vector(BLACK));
    //world.addObject(s8);


    sq1 = new Square(-I*20-J*20-K*50, -I*20+J*20-K*50, -I*20+J*20+K*80, -I*20-J*20+K*80);
    sq1->S = 0.;
    sq1->T = 0.;
    sq1->RI = 1.;
    sq1->color = Vector(BLACK);
    //world.addObject(sq1);

    sq2 = new Square(-I*15-J*10-K*50, -I*15+J*30-K*50, -I*15+J*30+K*60, -I*15-J*10+K*60);
    sq2->S = 1.;
    sq2->T = 0.;
    sq2->RI = 1.;
    sq2->color = Vector(WHITE);
    //world.addObject(sq2);

    ck1 = new Checkerboard( I, J, 50, 10 );
    ck1->S = 0.;
    ck1->T = 0;
    ck1->RI = 1.;
    ck1->color1 = Vector(BLACK);
    ck1->color2 = Vector(WHITE);
    world.addObject(ck1);

}


void design_world1(){
    //add light source to world
    ls1 = new LightSource( K*20 , 5., 1.);
    ls1->color = Vector(WHITE);
    ls1->intensity = 1.;
    world.addLightSource(ls1);

    //              origin,     R,   S,  T,  RI, color
    s1 = new Sphere(I*49.49-J*49.49-K*25, 20., 0.,  0.9,  1.33, Vector(DARKORCHID));
    world.addObject(s1);

    s2 = new Sphere(-I*70-K*25, 20., 0., 0.9, 1.33, Vector(BLUE));
    world.addObject(s2);

    s3 = new Sphere(J*70-K*25,  20., 0., 0.9, 1.33, Vector(DEEPSKYBLUE));
    world.addObject(s3);

    s4 = new Sphere(I*70-K*25,  20., 0., 0.9, 1.33, Vector(GREEN));
    world.addObject(s4);

    s5 = new Sphere(-J*70-K*25, 20., 0., 0.9, 1.33, Vector(YELLOW));
    world.addObject(s5);

    s6 = new Sphere(-I*49.49-J*49.49-K*25, 20., 0., 0.9, 1.3, Vector(ORANGE));
    world.addObject(s6);

    s7 = new Sphere(-I*49.49+J*49.49-K*25, 20., 0., 0.9, 1.33, Vector(RED));
    world.addObject(s7);

    s8 = new Sphere(I*49.49 + J*49.49-K*25, 20., 0., 1., 1., Vector(BLACK));
    world.addObject(s8);

    ck1 = new Checkerboard( I, J, 50, 10 );
    ck1->S = 0.;
    ck1->T = 0;
    ck1->RI = 1.;
    ck1->color1 = Vector(WHITE);
    ck1->color2 = Vector(DEEPSKYBLUE);
    world.addObject(ck1);

}
