#include "structs.h"
#include "importer3.c"

void subdivide()
{ 
	int i;
	for(i=0;i<fIndex;i++){
		faces[i].newFaceX=.25*(vertices[edges[faces[i].edge1].vert1].x+vertices[edges[faces[i].edge1].vert2].x+vertices[edges[faces[i].edge3].vert1].x+vertices[edges[faces[i].edge3].vert2].x);
		faces[i].newFaceY=.25*(vertices[edges[faces[i].edge1].vert1].y+vertices[edges[faces[i].edge1].vert2].y+vertices[edges[faces[i].edge3].vert1].y+vertices[edges[faces[i].edge3].vert2].y);
		faces[i].newFaceZ=.25*(vertices[edges[faces[i].edge1].vert1].z+vertices[edges[faces[i].edge1].vert2].z+vertices[edges[faces[i].edge3].vert1].z+vertices[edges[faces[i].edge3].vert2].z);
	}
	for (i=0;i<eIndex;i++){
		edges[i].newEdgeX=0.5*(vertices[edges[i].vert1].x  + vertices[edges[i].vert2].x );
		edges[i].newEdgeY=0.5*(vertices[edges[i].vert1].y  + vertices[edges[i].vert2].y );
		edges[i].newEdgeZ=0.5*(vertices[edges[i].vert1].z  + vertices[edges[i].vert2].z );
	}	
	for (i=0;i<vIndex;i++){
		int v1,v2,v3,v4,f1,f2,f3,f4;
		float qx,qy,qz,rx,ry,rz;
		// Q=.25*(q11+q13+q31+q33
		// R=0.25*((2*Porig)+.5*(p12+p21+p23p+p32))
		// Pnew= Q/4+ R/2 + Porig/4
			vertices[i].newVertX=vertices[i].x;
			vertices[i].newVertY=vertices[i].y;
			vertices[i].newVertZ=vertices[i].z;

		if(vertices[i].face4>-1){
			qx=0.25*(faces[vertices[i].face1].newFaceX+  faces[vertices[i].face2].newFaceX+  faces[vertices[i].face3].newFaceX+  faces[vertices[i].face4].newFaceX);
			qy=0.25*(faces[vertices[i].face1].newFaceY+  faces[vertices[i].face2].newFaceY+  faces[vertices[i].face3].newFaceY+  faces[vertices[i].face4].newFaceY);
			qz=0.25*(faces[vertices[i].face1].newFaceZ+  faces[vertices[i].face2].newFaceZ+  faces[vertices[i].face3].newFaceZ+  faces[vertices[i].face4].newFaceZ);
			
			int p1=-1,p2=-1,p3=-1,p4=-1;
			
			if(edges[vertices[i].edge1].vert1==i){
				p1=edges[vertices[i].edge1].vert2;
			}
			else{
				p1=edges[vertices[i].edge1].vert1;
			}

			if(edges[vertices[i].edge2].vert1==i){
				p2=edges[vertices[i].edge2].vert2;
			}
			else{
				p2=edges[vertices[i].edge2].vert1;
			}

			if(edges[vertices[i].edge3].vert1==i){
				p3=edges[vertices[i].edge3].vert2;
			}
			else{
				p3=edges[vertices[i].edge3].vert1;
			}

			if(edges[vertices[i].edge4].vert1==i){
				p4=edges[vertices[i].edge4].vert2;
			}
			else{
				p4=edges[vertices[i].edge4].vert1;
			}

			rx=0.25*(2*(vertices[i].x)+0.5*(vertices[p1].x+vertices[p2].x+vertices[p3].x+vertices[p4].x));
			ry=0.25*(2*(vertices[i].y)+0.5*(vertices[p1].y+vertices[p2].y+vertices[p3].y+vertices[p4].y));
			rz=0.25*(2*(vertices[i].z)+0.5*(vertices[p1].z+vertices[p2].z+vertices[p3].z+vertices[p4].z));
			
			vertices[i].newVertX=(0.25*vertices[i].x)+(qx/4)+(rx/2);
			vertices[i].newVertY=(0.25*vertices[i].y)+(qy/4)+(ry/2);
			vertices[i].newVertZ=(0.25*vertices[i].z)+(qz/4)+(rz/2);
		}
	}
}
void showSubdiv()
{
	int i=0;
	
	for(i=0;i<fIndex;i++)
	{
	
		int v1,v2,v3,v4;
		int v1v1,v1v2,v2v1,v2v2,v3v1,v3v2,v4v1,v4v2;
		
		v1=edges[faces[i].edge1].vert1;
		v2=edges[faces[i].edge1].vert2;
		v3=edges[faces[i].edge3].vert1;
		v4=edges[faces[i].edge3].vert2;
		
		glBegin(GL_LINE_STRIP);
			glVertex3f(faces[i].newFaceX,faces[i].newFaceY,faces[i].newFaceZ);
			glVertex3f(edges[vertices[v1].edge1].newEdgeX,edges[vertices[v1].edge1].newEdgeY,edges[vertices[v1].edge1].newEdgeZ);
			glVertex3f(vertices[v1].newVertX,vertices[v1].newVertY,vertices[v1].newVertZ );
			glVertex3f(edges[vertices[v1].edge2].newEdgeX,edges[vertices[v1].edge2].newEdgeY,edges[vertices[v1].edge2].newEdgeZ);
			glVertex3f(faces[i].newFaceX,faces[i].newFaceY,faces[i].newFaceZ);
		glEnd();

		glBegin(GL_LINE_STRIP);
			glVertex3f(faces[i].newFaceX,faces[i].newFaceY,faces[i].newFaceZ);
			glVertex3f(edges[vertices[v2].edge1].newEdgeX,edges[vertices[v2].edge1].newEdgeY,edges[vertices[v2].edge1].newEdgeZ);
			glVertex3f(vertices[v2].newVertX,vertices[v2].newVertY,vertices[v2].newVertZ );
			glVertex3f(edges[vertices[v2].edge2].newEdgeX,edges[vertices[v2].edge2].newEdgeY,edges[vertices[v2].edge2].newEdgeZ);
			glVertex3f(faces[i].newFaceX,faces[i].newFaceY,faces[i].newFaceZ);
		glEnd();

		glBegin(GL_LINE_STRIP);
			glVertex3f(faces[i].newFaceX,faces[i].newFaceY,faces[i].newFaceZ);
			glVertex3f(edges[vertices[v3].edge1].newEdgeX,edges[vertices[v3].edge1].newEdgeY,edges[vertices[v3].edge1].newEdgeZ);
			glVertex3f(vertices[v3].newVertX,vertices[v3].newVertY,vertices[v3].newVertZ );
			glVertex3f(edges[vertices[v3].edge2].newEdgeX,edges[vertices[v3].edge2].newEdgeY,edges[vertices[v3].edge2].newEdgeZ);
			glVertex3f(faces[i].newFaceX,faces[i].newFaceY,faces[i].newFaceZ);
		glEnd();

		glBegin(GL_LINE_STRIP);
			glVertex3f(faces[i].newFaceX,faces[i].newFaceY,faces[i].newFaceZ);
			glVertex3f(edges[vertices[v4].edge1].newEdgeX,edges[vertices[v4].edge1].newEdgeY,edges[vertices[v4].edge1].newEdgeZ);
			glVertex3f(vertices[v4].newVertX,vertices[v4].newVertY,vertices[v4].newVertZ );
			glVertex3f(edges[vertices[v4].edge2].newEdgeX,edges[vertices[v4].edge2].newEdgeY,edges[vertices[v4].edge2].newEdgeZ);
			glVertex3f(faces[i].newFaceX,faces[i].newFaceY,faces[i].newFaceZ);
		glEnd();
	}
	
}
