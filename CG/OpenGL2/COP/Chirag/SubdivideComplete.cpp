#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "SubdivideComplete.h"

#define ALPHA_MAX 20
#define ALPHA_LIMIT 0.469 /* converges to ~ 0.469 */

GLfloat ALPHA[] = {1.13333, -0.358974, -0.333333, 0.129032, 0.945783, 2.0,
						 3.19889, 4.47885, 5.79946, 7.13634, 8.47535, 9.80865,
						 11.1322, 12.4441, 13.7439, 15.0317, 16.3082, 17.574,
						 18.83, 20.0769};

#define BETA_MAX 20
#define BETA_LIMIT 0.469 /* converges to ~ 0.469 */

GLfloat BETA[] = {0.46875, 1.21875, 1.125, 0.96875, 0.840932, 0.75, 0.686349,
						0.641085, 0.60813, 0.583555, 0.564816, 0.55024, 0.5387,
						0.529419, 0.52185, 0.515601, 0.510385, 0.505987, 0.502247, 0.49904 };

#define NEWVERTEX 123.0

GLfloat alpha(GLuint n);
GLfloat beta(GLuint n);

	
WingedEdge* readOBJ(char* filename) {
	FILE* file;
	Model* model;
	WingedEdge* we;
	
	/* open the file */
	file = fopen(filename, "r");
	if (!file) {
		fprintf(stderr, "readOBJ() failed: can't open data file \"%s\".\n",
			filename);
		exit(1);
	}
    
	/* allocate a new model */
	model = new Model ;
	model->position = new Vertex ;
	model->position->x = 0.0;
	model->position->y = 0.0;
	model->position->z = 0.0;

	firstPass(model, file);

	rewind(file);

	we = secondPass(model, file);

	return we;
}

GLvoid firstPass(Model* model, FILE* file) {
	GLuint numVertices;
	GLuint numFaces;
	char buf[128];

	numVertices = numFaces = 0;

	while (fscanf(file, "%s", buf) != EOF) {
		switch (buf[0]) {
			case '#': /* comments*/
				/* eat up the rest of the line */
				fgets(buf, sizeof(buf), file);
				break;
			case 'v': /* a vertex! */
				/* ignore all but the simple case */
				numVertices++;
				fgets(buf, sizeof(buf), file);
				break;
			case 'f': /* a face! */
				numFaces++;
				fgets(buf, sizeof(buf), file);
				break;
			default: /* I don't care about the other cases! */
				fgets(buf, sizeof(buf), file);
				break;
		}
	}				

	model->numFaces = numFaces;
	model->numVertices = numVertices;
	/* Our work here is done. */
}

WingedEdge* secondPass(Model* model, FILE* file) {
	GLuint numVertices;
	GLuint numTriangles;
	GLuint v, f;
	GLuint v1, v2, v3;
	GLfloat x, y, z;
	Vertex** vertices = new Vertex*[model->numVertices];  /* array of vertices */
	Triangle** triangles = new Triangle*[model->numFaces];     /* array of triangles */
	Edge** edges = new Edge*[3 * model->numFaces]; /* array of edges */
	 /* List of faces! */
	WingedEdge* we;
	Face* previous;
	Face* current;
	Vertex* currv;
	Vertex* prevv;
	char buf[128];
	int i, j;

	numVertices = numTriangles= 0;

	while (fscanf(file, "%s", buf) != EOF) {
		switch (buf[0]) {
			case '#': /* comments */
				fgets(buf, sizeof(buf), file);
				break;
			case 'v': /* vertex! */
				fscanf(file, "%f %f %f", &x, &y, &z);
				vertices[numVertices] = new Vertex ;
				vertices[numVertices]->x = x;
				vertices[numVertices]->y = y;
				vertices[numVertices]->z = z;
				numVertices++;
				break;
			case 'f':
				fscanf(file, "%d %d %d", &v1, &v2, &v3);
				triangles[numTriangles] = new Triangle ;
				triangles[numTriangles]->verts[0] = v1 -1; /* THE -1 IS DAMN IMPORTANT! */
				triangles[numTriangles]->verts[1] = v2 -1;
				triangles[numTriangles]->verts[2] = v3 -1;
				numTriangles++;
				break;
			default: /* I don't care about the rest */
				fgets(buf, sizeof(buf), file);
				break;
		}
	}

	we = new WingedEdge ;
	we->faces = new Face ; /* allocate the first node */
	previous = current = we->faces; /* all roads lead to initial node */
	
	for (i=0; i < numTriangles; i++) {
		previous->next = current; /* link the last node in the list to the current node */
		for (j=0; j<3; j++) { /* Create the half edges and inform them of the vertices and face. */
			edges[3*i+j] = new Edge ;
			edges[3*i+j]->head = vertices[triangles[i]->verts[j%3]];
			edges[3*i+j]->tail = vertices[triangles[i]->verts[(j+1)%3]];
			edges[3*i+j]->left = current;
		}
		current->edge = edges[3*i]; /* associate an edge with the face */
		for (j=0; j<3; j++) {
			edges[3*i+j]->prev = edges[3*i+(j+1)%3];
			edges[3*i+j]->next = edges[3*i+(j+2)%3];
		}
		/* onward to the next face */
		previous = current;
		if (i+1 < numTriangles) current = new Face ;
	}
	for (i = 0; i < 3 * numTriangles -1; i++) {

		if (edges[i]->twin == NULL) {
			for (j = i+1; j < 3 * numTriangles; j++) {
				if (edges[j]->twin == NULL) {
					if (edges[j]->head == edges[i]->tail
						&& edges[i]->head == edges[j]->tail) {
						edges[i]->twin = edges[j];
						edges[j]->twin = edges[i];
					}
				}
			}
		}
	}
	
	prevv = we->vertices = vertices[0]; /* start at the beginning */
	
	for (i = 1; i < numVertices; i++) {
		currv = vertices[i];
		prevv->next = currv;
		prevv = currv;
	}

	return we;
}

/* unitize: "unitize" a model by translating it to the origin and
 * scaling it to fit in a unit cube around the origin.   Returns the
 * scalefactor used.
 *
 * we - pointer to the winged edge data classure
 */
GLfloat unitize(WingedEdge* we) {
	GLfloat maxx, minx, maxy, miny, maxz, minz;
	GLfloat cx, cy, cz, w, h, d;
	GLfloat scale;
	Vertex* vertex;
	 
	assert(we);
	assert(we->vertices);
	/* and we'll just hope that the rest is ok */
	 
	vertex = we->vertices;
	 
	/* get the max/mins */
	maxx = minx = vertex->x;
	maxy = miny = vertex->y;
	maxz = minz = vertex->z;
	while (vertex) {
		if (maxx < vertex->x) maxx = vertex->x;
		if (minx > vertex->x) minx = vertex->x;
        
		if (maxy < vertex->y) maxy = vertex->y;
		if (miny > vertex->y) miny = vertex->y;

		if (maxz < vertex->z) maxz = vertex->z;
		if (minz > vertex->z) minz = vertex->z;

		vertex = vertex->next;
	}
    
	/* calculate model width, height, and depth */
	w = sabs(maxx) + sabs(minx);
	h = sabs(maxy) + sabs(miny);
	d = sabs(maxz) + sabs(minz);
    
	/* calculate center of the model */
	cx = (maxx + minx) / 2.0;
	cy = (maxy + miny) / 2.0;
	cz = (maxz + minz) / 2.0;

	/* calculate unitizing scale factor */
	scale = 2.0 / sqrt(w*w+h*h+d*d);
    
	/* translate around center then scale */
	vertex = we->vertices;
	while (vertex) {
		vertex->x -= cx;
		vertex->y -= cy;
		vertex->z -= cz;
		vertex->x *= scale;
		vertex->y *= scale;
		vertex->z *= scale;
		
		vertex = vertex->next;
	}
	
	return scale;
}

/* glmFacetNormals: Generates facet normals for a model (by taking the
 * cross product of the two vectors derived from the sides of each
 * triangle).  Assumes a counter-clockwise winding.
 *
 * we - pointer to winged edge data classure
 */
GLvoid facetNormals(WingedEdge* we) {
    Face* face;
	 Edge* edge;
    Vertex* edge1;
	 Vertex* edge2;
	 
    assert(we);
    assert(we->faces);
	 assert(we->faces->edge);
	 /* and the rest we'll just pretend are ok */

	 face = we->faces;
	 
	 while (face) {
		 edge1 = new Vertex ;
		 edge2 = new Vertex ;

		 edge1->x = face->edge->tail->x - face->edge->head->x;
		 edge1->y = face->edge->tail->y - face->edge->head->y;
		 edge1->z = face->edge->tail->z - face->edge->head->z;

		 edge2->x = face->edge->prev->tail->x - face->edge->prev->head->x;
		 edge2->y = face->edge->prev->tail->y - face->edge->prev->head->y;
		 edge2->z = face->edge->prev->tail->z - face->edge->prev->head->z;

		 face->normal = scross(edge1, edge2);
		 snormalize(face->normal);
		 
		 free(edge1); free(edge2);

		 face = face->next;
	 }
}

GLvoid vertexNormals(WingedEdge* we) {
	/* I'll add this later */
}

GLfloat sabs(GLfloat f) {
	return (f < 0 ? -f : f);
}

GLfloat smax(GLfloat a, GLfloat b) {
	return (b > a ? b : a);
}

GLfloat sdot(Vertex* u, Vertex* v) {
	assert(u); assert(v);

	return u->x * v->x + u->y * v->y + u->z * v->z;
}

Vertex* scross(Vertex* u, Vertex* v) {
	Vertex* result;

	assert(u); assert(v);

	result = new Vertex ;

	result->x = u->y * v->z - u->z * v->y;
	result->y = u->z * v->x - u->x * v->z;
	result->z = u->x * v->y - u->y * v->x;

	return result;
}

GLvoid snormalize(Vertex* v) {
	GLfloat l;

	assert(v);

	l = (GLfloat)sqrt(sdot(v,v));
	v->x /= l;
	v->y /= l;
	v->z /= l;
}


GLvoid subdivide(WingedEdge* we) {
	Vertex* vertex;

	vertex =	we->vertices;
	while (vertex) {
		vertex->newpoint = GL_FALSE;
		vertex = vertex->next;
	}
	firstDivision(we->faces);
	secondDivision(we->faces);
}

GLvoid firstDivision(Face* face) {
	Edge* edge;
	Vertex* vertex;
	Vertex* m;
	Edge* newedge;
	Edge* twinedge;

	edge = face->edge;

	do {
		assert(edge);
		assert(edge->next);
		assert(edge->next->twin);
		assert(edge->next->twin->next);

		if (edge->next->twin->next->twin != edge) { /* There is work here to be done! */
			/* get the midpoint */
			m = midpoint(edge->head, edge->tail);
			m->newpoint = GL_TRUE; /* flag this one as new! */
		
			/* insert the new vertex into the list */
			vertex = edge->tail->next;
			edge->tail->next = m;
			m->next = vertex;

			/* create new edge */
			newedge = new Edge ;
			newedge->head = edge->head;
			newedge->tail = m;
			newedge->prev = edge;
			newedge->next = edge->next;
			edge->next->prev = newedge;
			edge->next = newedge;
			newedge->twin = edge->twin;
			edge->head = m;
			edge->twin->twin = newedge;

			/* create a new edge for the twin */
			twinedge = new Edge ;
			twinedge->head = edge->twin->head;
			twinedge->tail = m;
			twinedge->prev = edge->twin;
			twinedge->next = edge->twin->next;
			edge->twin->next->prev = twinedge;
			edge->twin->next = twinedge;
			twinedge->twin = edge;
			edge->twin->head = m;
			edge->twin = twinedge;

			firstDivision(edge->next->twin->left);
		}
		edge = edge->next->next;
	} while (edge != face->edge);
}

GLvoid secondDivision(Face* faces) {
	Edge* edge;
	Vertex* vertex;
	Vertex* m;
	Edge* newedge;
	Edge* twinedge;
	Face* face;
	Face* newface;
	Face* faceptr;
	
	face = faces;

	/* first let's add some new edges */
	while (face) {
		
		edge = face->edge;

		do {
			newedge = new Edge ;

			newedge->head = edge->prev->tail;
			newedge->tail = edge->head;
			newedge->next = edge->prev;
			newedge->prev = edge;
			newedge->left = NULL;

			/* this is how we'll keep track of the new edges */
			edge->prev->prev = newedge; 
			
			twinedge = new Edge ;
			twinedge->head = newedge->tail;
			twinedge->tail = newedge->head;
			twinedge->twin = newedge;
			newedge->twin = twinedge;
			twinedge->left = NULL;

			edge = edge->next->next;
		} while (edge != face->edge);
		face = face->next;
	}
	
	face = faces;
	while (face) {
		if (face->edge->right != face->edge->left) { /* make sure to skip the new faces */
			/* add the 3 corner faces (actually, we reuse one) */
			newedge = edge = face->edge;
			do {
				if (edge != newedge) { /* is this really a new face? */
					newface = new Face ;
					/* add the new face to the list */
					faceptr = face->next;
					face->next = newface;
					newface->next = faceptr;
				} else {
					newface = face;
				}
				/* tell all the edges about this new face */
				edge->left = newface;
				edge->prev->left = newface;
				edge->prev->prev->left = newface;
				
				/* assign an edge to the new face */
				assert(newface);
				newface->edge = edge;
				edge->right = edge->left; /* mark this face as new! */
				edge = edge->next->next;
			} while (edge != newedge);

			edge = face->edge;

			edge->right = edge->left;
			
			/* add the inner face */
			newface = new Face ;
			
			/* add the new face to the list */
			faceptr = face->next;
			face->next = newface;
			newface->next = faceptr;

			/* assign an edge to the new face */
			newface->edge = edge->prev->prev->twin;

			/* complete the inner edges */
			do {
				newedge = edge->prev->prev->twin;
				newedge->next = edge->next->prev->twin;
				newedge->next->prev = newedge;
				/* tell all the edges about this new face */
				newedge->left = newface;
				newedge->right = newedge->left;
				edge = edge->next->next;
			} while (edge != face->edge);
			/* complete the outer edges */
			edge = face->edge;
			do {
				edge->next = edge->prev->prev;
				edge = edge->next->twin->next->twin->prev; /* phew! */
			} while (edge != face->edge);
			edge = face->edge;
			do {
				edge->prev->prev = edge->next;
				edge = edge->next->twin->next->twin->prev; /* phew! */
			} while (edge != face->edge);
		}
		face = face->next;
	}
	face = faces;
	while (face) { /* now to add those right faces */
		edge = face->edge;
		do {
			edge->right = edge->twin->left;
			edge = edge->next;
		} while (edge != face->edge);
		face = face->next;
	}
}




GLvoid refine(WingedEdge* we) {
	Vertex* vertex;
	Vertex* avg;
	Face* face;
	Edge* edge;
	Edge* inneredge;
	Edge* firstEdge;
	GLuint n;
	
	vertex = we->vertices;

	while (vertex) {
		vertex->averaged = NULL;
		vertex = vertex->next;
	}

	face = we->faces;
	
	while (face) {
		edge = face->edge;
		
		do {
			if (edge->head->averaged == NULL) {
				inneredge = edge;
				n = 0;
				edge->head->averaged = new Vertex ;
				avg = edge->head->averaged;
				avg->x = avg->y = avg->z = 0.0;
				do {
					avg->x += inneredge->tail->x;
					avg->y += inneredge->tail->y;
					avg->z += inneredge->tail->z;
					inneredge = inneredge->next->twin;
					n++;
				} while (inneredge != edge);
				avg->x += edge->head->x * alpha(n);
				avg->y += edge->head->y * alpha(n);
				avg->z += edge->head->z * alpha(n);
				avg->x /= alpha(n) + n;
				avg->y /= alpha(n) + n;
				avg->z /= alpha(n) + n;
			}
			edge = edge->next;
		} while (edge != face->edge);
		face = face->next;
	}

	vertex = we->vertices;

	while (vertex) {
		vertex->x = vertex->averaged->x;
		vertex->y = vertex->averaged->y;
		vertex->z = vertex->averaged->z;

		free(vertex->averaged);
		vertex = vertex->next;
	}
}

GLfloat alpha(GLuint n) {
	GLfloat b;

	if (n <= 20) return ALPHA[n-1];
	
	b = beta(n);
	
	return n * (1 - b) / b; 
}

/* return some pre-generated betas */
GLfloat beta(GLuint n) {
	return (5.0/4.0 - (3+2*cos(2*M_PI / n)) * (3+2*cos(2*M_PI / n)) / 32);
}



Vertex* midpoint(Vertex* v1, Vertex* v2) {
	Vertex* m;

	m = new Vertex ;
	m->x = (v1->x + v2->x) / 2.0;
	m->y = (v1->y + v2->y) / 2.0;
	m->z = (v1->z + v2->z) / 2.0;

	return m;
}

long faceCount(WingedEdge* we) {
	Face* face;
	long count;

	count = 0;
	face = we->faces;
	while (face) {
		count++;
		face = face->next;
	}
	return count;
}

long vertexCount(WingedEdge* we) {
	Vertex* vertex;
	long count;

	count = 0;
	vertex = we->vertices;
	while (vertex) {
		count++;
		vertex = vertex->next;
	}
	return count;
}
