#include "openGL.h"

OpenGLContext::OpenGLContext(void) {  
	// OpenGLContext(0, char *argv);
}  

OpenGLContext::OpenGLContext(int argc, char *argv) {  
	Initialize(argc, argv);	
	glutMainLoop();	
	exit(EXIT_SUCCESS);
}  

OpenGLContext::bool reshapeWindow(int CurrentWidth, int CurrentHeight){
	windowHeight=CurrentHeight;
	windowWidth=CurrentWidth;
	glViewport(0, 0, CurrentWidth, CurrentHeight);
}

OpenGLContext::void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
	glutPostRedisplay();
}
OpenGLContext::void Initialize(int argc, char* argv[])
{
	InitWindow(argc, argv);
	fprintf(
		stdout,
		"INFO: OpenGL Version: %s\n",
		glGetString(GL_VERSION)
		);
	
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

OpenGLContext::void InitWindow(int argc, char* argv[])
{
	glutInit(&argc, argv);
	
	glutInitContextVersion(4, 0);
	glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	
	glutInitWindowSize(CurrentWidth, CurrentHeight);
	
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	
	WindowHandle = glutCreateWindow(WINDOW_TITLE_PREFIX);
	
	if(WindowHandle < 1) {
		fprintf(stderr,"ERROR: Could not create a new rendering window.\n");
		exit(EXIT_FAILURE);
	}
	
	glutReshapeFunc(ResizeFunction);
	glutDisplayFunc(RenderFunction);
}