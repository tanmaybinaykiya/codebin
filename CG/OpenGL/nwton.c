#include <stdlib.h>
#include <ifstream.h>
#include <GL/glut.h>

#define Ball(I,J) ball_pos[(J) + (I)*count]

struct R3{
  float x;
  float y;
  float z;
}; // end R3

// define a few globals.  There's no way around it with all
// the function pointers used by OpenGL.
static int spinx = 0, spinz = 0, rotate = 0, origx, origz; 
static int count, Index, steps, stepIndex = 0, stepsize = 1, outEvery;
static int outCount = 0;
static R3 *hook_pos, *ball_pos;
static float radius;
static int animationFlag = 1;

ifstream datafile;

// define the model colors
GLfloat blue[] = {0.1, 0.1, 0.9, 1.};
GLfloat darkred[] = {0.6, 0.1, 0.1, 1.0};
GLfloat red[] = {1.0, 0.0, 0.0, 1.0};
GLfloat lightgray[] = {0.75, 0.75, 0.75, 1.0};
GLfloat gray[] = {0.5, 0.5, 0.5, 1.0};
GLfloat darkgray[] = {0.25, 0.25, 0.25, 1.0}; 
GLfloat light_position[] = {0.5, 3.0, 2.0, 1.0};

// c - camera position, v - focus, u - upward direction
static float cx = 0.0, cy = 6.0, cz = 2.0, vx = 0.0, vy = 0.0, vz = -2.0;
static float ux =  0.0, uy = 0.0, uz = 1.0;

// Declare the display lists
GLuint ball;

void mouse(int button, int state, int x, int z)
  // Record cursor position in response to mouse button action
{
  switch(button){
  case GLUT_LEFT_BUTTON:
    if (state == GLUT_DOWN) {
      origx = x;
      origz = z;
      rotate = 1;
    } else {
      rotate = 0;
    }
    break;
  }
} // end mouse


void motion(int x, int z)
  // Rotate the view on mouse event
{
  // calculate rotation angles due to mouse action
  if(rotate){
    // Update the view if mouse button 1
    spinz = (spinz + (x - origx))%360;
spinx = (spinx + (z - origz))%360;
origx = x;
    origz = z;
    // tell engine to redisplay
    glutPostRedisplay();
  }
} // end motion


void keyboard(unsigned char key, int xPos, int yPos)
  // Respond to keyboard events
{
  switch(key){
  case 27: // exit on ESC
    exit(0);
  case 43: // move forward on +
    cy -= 0.5;
    glLoadIdentity();
    gluLookAt(cx, cy, cz, vx, vy, vz, ux, uy, uz);
    break;
  case 45: // move backward on -
    cy += 0.5;
    glLoadIdentity();
    gluLookAt(cx, cy, cz, vx, vy, vz, ux, uy, uz);
    break;
  case 60: // advance one frame backward on < 
    stepIndex--;
    if(stepIndex < 0)
      stepIndex = 0;
    break;
  case 62: // advance one frame forward on >
    stepIndex++;
    if(stepIndex >= steps)
      stepIndex = steps - 1;
    break;
  }
  // You can put in many more for the camera position,
  // focus point, and upward direction (or whatever else).
} // end keyboard


void idle(void)
  // What to do during idle time
{
  if(animationFlag){
    stepIndex += stepsize;
    outCount += stepsize;
    if(stepIndex >= steps || stepIndex < 0)
      stepIndex -= stepsize;
    else if(abs(outCount) > outEvery){
      // Update run %
cout << stepIndex*100/steps << "%" << endl;
outCount = 0;
    }
  }
  // tell the engine to redisplay
  glutPostRedisplay();
} // end idle


void reshape(int w, int h)
  // What to do on window creation and resize
{
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 40.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(cx, cy, cz, vx, vy, vz, ux, uy, uz);
} // end reshape


void menu(int item)
  // what actions to take for menu options
{
  int temp;

  switch(item){
  case 0:
    exit(0);
  case 1:
    animationFlag = !animationFlag;
    break;
  case 2:
    stepsize *= -1;
    break;
  case 3:
    stepsize *= 2;
    break;
  case 4:
    temp = stepsize;
    if(temp /= 2)
      stepsize /= 2;
    break;
  }
} // end menu


void drawStick(void)
  // Draw the stick
{
  // Color the sticks
  glShadeModel(GL_FLAT);
  glMaterialfv(GL_FRONT, GL_SPECULAR, darkred); 
  glMaterialfv(GL_FRONT, GL_AMBIENT, red);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, darkred); 

  glBegin(GL_LINES);
    glVertex3f(hook_pos[Index].x, hook_pos[Index].y, hook_pos[Index].z);
    glVertex3f(Ball(stepIndex, Index).x, Ball(stepIndex, Index).y, Ball(stepIndex, Index).z);
  glEnd();
} // end drawStick


void display(void)
  // The main display routine
{
  // Clear frame and buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Push initial position onto the stack
  glPushMatrix();

  // Rotate initial matrix in response to mouse action
  glRotatef((GLfloat) spinx, 1.0, 0.0, 0.0);
  glRotatef((GLfloat) spinz, 0.0, 0.0, 1.0);

  // Draw the balls and sticks
  for(Index = 0; Index < count; ++Index){
    glPushMatrix();
    drawStick();
    glTranslatef(Ball(stepIndex, Index).x, Ball(stepIndex, Index).y, Ball(stepIndex, Index).z);
    glCallList(ball);
    glPopMatrix();
  }

  // pop back to initial position
  glPopMatrix();
  // flush the command list
  glFinish();
  // Swap buffers
  glutSwapBuffers();
} // end display 


void displayLists(void)
  // This creates the necessary display lists.  There is not
  // one for the sticks because these are drawn dynamically
  // by drawStick()
{
  // Create the ball list
  ball = glGenLists(1);
  glNewList(ball, GL_COMPILE);
    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_SPECULAR, lightgray); 
    glMaterialfv(GL_FRONT, GL_AMBIENT, darkgray);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
    if(radius > 0.5)
      glutSolidSphere(radius, 20, 20);
    //glutSolidCube(radius); // Try cubes for fun
    else
      glutSolidSphere(radius, 15, 15);
    //glutSolidCube(radius); // Try cubes for fun
  glEndList();
} // end displayLists


void init(void)
  // Initialize the problem
{   
  // set background to black
  glClearColor(0.0, 0.0, 0.0, 0.0);
  // set shininess of objects  
  glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 50.0);
  
  // Set lighting 
  glLightfv(GL_LIGHT0, GL_SPECULAR, lightgray);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, gray);
  glLightfv(GL_LIGHT0, GL_AMBIENT, darkgray);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  // Enable lighting and a few others
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST); // Test to see which objects are in front of others
  glEnable(GL_CULL_FACE);  // Enable skipping of drawing specified face
  glCullFace(GL_BACK);     // Here, don't waste time drawing the back of object
  glLineWidth(3.f);        // Set linewidth to 3.  Default is 1

  // Create the display lists (one for the balls)
  displayLists();
} // end init


void gridRead()
  // This funstion reads in the configuration of the Newtons cradle.
  // The first line of the file should contain the number of pendula
  // and ball width.
{
  ifstream infile;

  infile.open("setup.dat");
  if(!infile){
    cerr << "Setup file could not be opened." << endl;
    exit(1);
  }
  
  infile >> count >> radius;

  // allocate space
  hook_pos = new R3[count];

  cout << count << " balls" << endl;
  for(int i = 0; i < count; ++i){
    infile >> hook_pos[i].x >> hook_pos[i].y >> hook_pos[i].z;
  }

  infile.close();
} // end gridRead


void positionRead()
  // This funstion reads in the configuration of the Newtons cradle.
  // The first line of the file should contain the number of pendula
  // and ball width.
{
  float x;

  // open position data file stream
  datafile.open("positions.dat");
  if(!datafile){
    cerr << "Positions infile could not be opened." << endl;
    exit(1);
  }

  // First, count the number of steps taken
  while(!datafile.eof()){
    ++steps;
    for(int i = 0; i < count; ++ i){
      datafile >> x >> x >> x;
    } 
  }
  --steps;

  datafile.close();
  datafile.open("positions.dat");
  if(!datafile){
    cerr << "Position infile could not be opened second time." << endl;
    exit(1);
  } 

  cout << steps << " time steps" << endl;
  outEvery = steps/100;
  // Allocate space
  ball_pos = new R3[count*steps];

  for(int i = 0; i< steps; ++i)
    for(int j = 0; j < count; ++j)
      datafile >> Ball(i,j).x >> Ball(i,j).y >> Ball(i,j).z;

  // Close the datafile
  datafile.close();
  
} // end positionRead

int main(int argc, char** argv)
{
  // Read in grid for hooks
  gridRead();
  // Read in body positions
  positionRead();

  glutInit(&argc, argv); // initialize glut
  // Initialize display for double buffering, rgba mode, and 
  // depth calculations
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  // Size the window
  glutInitWindowSize(450, 450);
  // Position the window
  glutInitWindowPosition(150, 150);
  // Create and title the window
  glutCreateWindow("Newton's Cradle");
  // Initialize problem
  init();
  // Let us now begin
  glutDisplayFunc(display);
  // Reshape when window size is changed
  glutReshapeFunc(reshape);
  // Do something while idle
  glutIdleFunc(idle);
  // Create a menu
  glutCreateMenu(menu);
  // Add some options to the menu
  glutAddMenuEntry("Toggle animation", 1);
  glutAddMenuEntry("Reverse motion", 2);
  glutAddMenuEntry("Faster", 3);
  glutAddMenuEntry("Slower", 4);
  glutAddMenuEntry("Exit", 0);
  // Tell how to open menu
  glutAttachMenu(GLUT_MIDDLE_BUTTON);
  // Tell openGL what to do on mouse button events
  glutMouseFunc(mouse);
  // Tell openGL what to do on mouse movement events
  glutMotionFunc(motion);
  // Tell openGL what to do on keyboard events
  glutKeyboardFunc(keyboard);       
  // Go into infinite execution loop
  glutMainLoop();
  return 0;
}
