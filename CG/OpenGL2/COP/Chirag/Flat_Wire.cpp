#include "SubdivideComplete.h"
#include <stdio.h>

#define T(x) (model->triangles[(x)])

void flatObject(WingedEdge* we){
	Face* face;
	Edge* edge;
	Edge* firstEdge;

	face= we->faces;
	while (face){

		firstEdge = edge = face->edge;
		glBegin(GL_TRIANGLES);
		glNormal3f(face->normal->x, face->normal->y, face->normal->z);

		do{
			glVertex3f(edge->head->x, edge->head->y, edge->head->z);
			edge=edge->next;
		} while (firstEdge != edge);

		glEnd();

		face=face->next;
	}
}

void wireObject(WingedEdge* we){
	Face* face;
	Edge* edge;
	Edge* firstEdge;
	long num=0;

	face= we->faces;
	while (face){

		firstEdge = edge = face->edge;
		glBegin(GL_LINE_LOOP);
		glNormal3f(face->normal->x, face->normal->y, face->normal->z);

		do{
			glVertex3f(edge->head->x, edge->head->y, edge->head->z);
			edge=edge->next;
		} while (firstEdge != edge);

		glEnd();

		face=face->next;
		num++;
	}

	printf("Faces shown: %d\n",num);
}
