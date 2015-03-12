#include <stdio.h> // Include the GLEW header file  

#include <GL/gl.h> // Include the GLEW header file  
  
#include <GL/glut.h> // Include the GLUT header file  
int x=10;
//bool* keyStates = new bool[256]; // Create an array of boolean values of length 256 (0-255)  
  
void display (void) {  
  
glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // Clear the background of our <a title="window" href="http://www.swiftless.com/tutorials/opengl/window.html">window</a> to red  
glClear(GL_COLOR_BUFFER_BIT); //Clear the colour buffer (more buffers later on)  
glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations  
  
glTranslatef(0.0f, 0.0f, -5.0f); // <a title="Push" href="http://www.swiftless.com/tutorials/opengl/pop_and_push_matrices.html">Push</a> eveything 5 units back into the scene, otherwise we won't see the primitive  

glRotatef(x,25,x,x);  
x+=10;
glutWireSphere(2, 5,5);  
printf("%d \n ",x);  
sleep(100);
glFlush(); // Flush the OpenGL buffers to the window  
}  
  
void reshape (int width, int height) {  
glViewport(0, 0, (GLsizei)width, (GLsizei)height); // Set our viewport to the size of our window  
glMatrixMode(GL_PROJECTION); // Switch to the projection matrix so that we can manipulate how our scene is viewed  
glLoadIdentity(); // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)  
gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0); // Set the Field of view angle (in degrees), the aspect ratio of our window, and the new and far planes  
glMatrixMode(GL_MODELVIEW); // Switch back to the model view matrix, so that we can start drawing shapes correctly  
  
}  
  
void keyPressed (unsigned char key, int x, int y) {  
}  
  
void keyUp (unsigned char key, int x, int y) {  
}  
  
int main (int argc, char **argv) {  
glutInit(&argc, argv); // Initialize GLUT  
glutInitDisplayMode (GLUT_SINGLE); // Set up a basic display buffer (only single buffered for now)  
glutInitWindowSize (500, 500); // Set the width and height of the window  
glutInitWindowPosition (100, 100); // Set the position of the window  
glutCreateWindow ("You’re first OpenGL Window"); // Set the title for the window  
  
glutDisplayFunc(display); // Tell GLUT to use the method "display" for rendering  
glutIdleFunc(display);  
  
glutReshapeFunc(reshape); // Tell GLUT to use the method "reshape" for reshaping  
  
glutKeyboardFunc(keyPressed); // Tell GLUT to use the method "keyPressed" for key presses  
glutKeyboardUpFunc(keyUp); // Tell GLUT to use the method "keyUp" for key up events  
glutMainLoop(); // Enter GLUT's main loop  
}  
