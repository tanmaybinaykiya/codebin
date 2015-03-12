#include <stdio.h>
#include <GL/gl.h> // Include the GLEW header file
#include <GL/glut.h> // Include the GLUT header file

void display (void)
{
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f); // Clear the background of our window to red
    glClear(GL_COLOR_BUFFER_BIT); //Clear the colour buffer (more buffers later on)
    glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations
//  	gluOrtho2D(-6,10,-6,10);          //ortho function to map 3d to 2d
     glColor3ub(255,0,0);                   /* Set the colour rgb, 0-255 */
GLint i;
  GLfloat xy;

  glColor3f(0.0,1.0,0.0);                /* Set colour rgb, 0.0 - 1.0 */


  glBegin(GL_QUADS);                     // Quads this time
   for (i=0, xy=0.0 ;i<10;i++, xy-=0.1) {
     glColor4f(1.0,1.0+xy,0.0,0.4);      // Set colour rgba, 0.0 - 1.0
     glVertex3f(xy,xy,-6.0);             // Now define 4 corners
     glVertex3f(xy-1.0,xy,-6.0);
     glVertex3f(xy-1.0,xy-1.0,-6.0);
     glVertex3f(xy,xy-1.0,-6.0);
   }
  glEnd();
  glFlush(); // Flush the OpenGL buffers to the window
}

void reshape (int width, int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);                  // Set our viewport to the size of our window
    glMatrixMode(GL_PROJECTION);                              // Switch to the projection matrix so that we can manipulate how our scene is viewed
    glLoadIdentity();                                         // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)
    gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0); // Set the Field of view angle (in degrees), the aspect ratio of our window, and the new and far planes
    glMatrixMode(GL_MODELVIEW); // Switch back to the model view matrix, so that we can start drawing shapes correctly
}

int main (int argc, char **argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode ( GLUT_RGBA | GLUT_SINGLE); // Set up a basic display buffer (only single buffered for now)
    glutInitWindowSize (500,500); // Set the width and height of the window
    glutInitWindowPosition (0, 00); // Set the position of the window

    glutCreateWindow ("Tanmay"); // Set the title for the window
    glutDisplayFunc(display); // Tell GLUT to use the method "display" for rendering
    glutReshapeFunc(reshape); // Tell GLUT to use the method "reshape" for rendering

    glutMainLoop(); // Enter GLUT's main loop
}
