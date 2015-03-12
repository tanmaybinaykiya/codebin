#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
int x=50,y=30,sx=-25,sy=-30;
//const int   A = 500;  /* length of a side of the monitor window */
//const float B = 500;  /* length of a side of the clipping rectangle */
//const float C = 200;  /* length of a side of the square the program draws */

void keyboardFunc (unsigned char key, int x, int y) 
{
    if (key==27)        
    exit(0);         
}
void calc()
{
      if ((x>=500) || (x<=00))
         sx=-sx;
      if ((y>=500) || (y<=00))
         sy=-sy;

      x+=sx;
      y+=sy;
      printf("%d,%d  \n",x,y);
}
void myinit(void)
{
    glClearColor(0.2, 0.2, 0.2, 0.0); /* gray background */
    glMatrixMode(GL_PROJECTION);      /* In World coordinates: */
    glLoadIdentity();                 /* position the "clipping rectangle" */
    gluOrtho2D( -1, 501, -1, 501);/* at -B/2, its right edge at +B/2, its bottom */
    glMatrixMode(GL_MODELVIEW);       /* edge at -B/2 and its top edge at +B/2 */
}

void display (void) 
{

    glClear(GL_COLOR_BUFFER_BIT); //Clear the colour buffer (more buffers later on)
    glPointSize(5);
    glLoadIdentity(); 
    glBegin(GL_POINTS) ;
        glColor3f ( 1.0, 0, 0);
        calc();
        glVertex2i( x, y );        
    glEnd();
    glFlush(); // Flush the OpenGL buffers to the window
    sleep(50);

}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE);
         glutInitWindowSize( 500, 500);      

    glutCreateWindow("My Rectangle");
    myinit();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardFunc); // Tell GLUT to use the method "keyPressed" for key presses
	glutIdleFunc(display);
    glutMainLoop();
    return 1;
}
