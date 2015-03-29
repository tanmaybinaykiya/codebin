#define GLM_FORCE_RADIANS 
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4, glm::ivec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include <glm/ext.hpp>
#include <iostream>
#define WINDOW_TITLE_PREFIX "Chapter 4"

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <GL/glew.h>
#include <GL/freeglut.h>
static const double PI = 3.14159265358979323846;

#define DegreesToRadians(degrees) degrees*(float)(PI/180)


typedef struct Vertex{
	float Position[4];
	float Color[4];
} Vertex;

int CurrentWidth = 800, CurrentHeight = 600, WindowHandle = 0;

unsigned int FrameCount = 0;

GLuint
ProjectionMatrixUniformLocation,
ViewMatrixUniformLocation,
ModelMatrixUniformLocation,
BufferIds[3] = { 0 },
ShaderIds[3] = { 0 };

glm::mat4
ProjectionMatrix,
ViewMatrix,
ModelMatrix;

float CubeRotation = 0;
clock_t LastTime = 0;

void Initialize(int, char*[]);
void InitWindow(int, char*[]);
void ResizeFunction(int, int);
void RenderFunction(void);
void TimerFunction(int);
void IdleFunction(void);
void CreateCube(void);
void DestroyCube(void);
void DrawCube(void);
void ExitOnGLError(const char* error_message);
GLuint LoadShader(const char* filename, GLenum shader_type);
