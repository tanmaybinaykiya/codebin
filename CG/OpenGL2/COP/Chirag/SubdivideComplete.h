#include <GL/glut.h>
#include <stdio.h>
#include <memory.h>

#pragma warning (disable:4018)
#pragma warning (disable:4101)

#ifndef M_PI
#define M_PI 3.14159265f
#endif

class Triangle {
public :
	Triangle(){memset(this,0,sizeof(Triangle));}
	GLuint verts[3];
} ;

class Vertex {
public :
	Vertex(){memset(this,0,sizeof(Vertex)) ;}
	GLfloat x, y, z;
	GLboolean newpoint;
	class Vertex* averaged; /* used for subdivision */
	class Vertex* next; /* no geometric meaning - just a list */
} ;

class Edge {
public :
	Edge(){memset(this,0,sizeof(Edge)) ;}
	class Vertex* head;
	class Vertex* tail;
	
	class Edge* next;
	class Edge* prev;
	class Edge* twin;

	class Face* left;
	class Face* right;
} ;

class Face {
public :
	Face(){	memset(this,0,sizeof(Face)) ;}
	class Edge* edge;

	class Vertex* normal;
	
	class Face* next; /* no geometric meaning - just a list */

} ;

class WingedEdge {
public :
	WingedEdge(){memset(this,0,sizeof(WingedEdge)) ;}
	class Face* faces;
	class Vertex* vertices;
	/* edges are already uniquely ordered by the faces */
} ;

class Model {
public :
	Model(){memset(this,0,sizeof(Model)) ;}
	GLuint numVertices;
	GLuint numFaces;

	Vertex* position;
} ;

WingedEdge* readOBJ(char* filename);
GLvoid firstPass(Model* model, FILE* file);
WingedEdge* secondPass(Model* model, FILE* file);
GLfloat unitize(WingedEdge* we);
GLvoid facetNormals(WingedEdge* we);
GLvoid vertexNormals(WingedEdge* we);
GLfloat sabs(GLfloat f);
GLfloat smax(GLfloat a, GLfloat b);
GLfloat sdot(Vertex* u, Vertex* v);
Vertex* scross(Vertex* u, Vertex* v);
GLvoid snormalize(Vertex* v);
GLvoid subdivide(WingedEdge* we);
GLvoid firstDivision(Face* face);
GLvoid secondDivision(Face* face);
GLvoid refine(WingedEdge* we);
Vertex* midpoint(Vertex* v1, Vertex* v2);
long faceCount(WingedEdge* we);
long vertexCount(WingedEdge* we);


void wireObject(WingedEdge* we) ;
void flatObject(WingedEdge* we) ;
