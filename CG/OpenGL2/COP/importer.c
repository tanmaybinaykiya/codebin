/*
 * importer.c
 * 
 * Copyright 2013 Tanmay <binaykiya.tanmay@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 * input filename hardocoded into code
 * input file line size should not exceed 128 characters
 * 		line starting with ' ' or '#'  is treated as a comment
 * 		line starting with v should contain 3 parameters (x, y, z)seperated by a ','character. 
 * 		line starting with f should contain 4 parameters (vertex1, vertex2, vertex3, vertex4) all in the clockwise order seperated by a ','character
 */



#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
const int maxVertices=50;
const int maxEdges=50;
const int maxFaces=15;

int vIndex=0, eIndex=0, fIndex=0;

struct vertex typedef vertex;
struct edge typedef edge;
struct face typedef face;

struct vertex {
	float x;
	float y;
	float z;
	
	int edge1;
	int edge2;
	int edge3;
	int edge4;
	
	int face1;
	int face2;
	int face3;
	int face4;

	float newVertX;
	float newVertY;
	float newVertZ;
};

struct edge{
	int vert1;
	int vert2;
	
	int face1;
	int face2;
	
	float newEdgeX;
	float newEdgeY;
	float newEdgeZ;
};

struct face{
	int edge1;
	int edge2;
	int edge3;
	int edge4;
	
	float newFaceX;
	float newFaceY;
	float newFaceZ;
};

void createVertex(int v,float x,float y,float z);
int createEdge(int fIndex,int edgeFace,int edgeIndex,int v1, int v2);
void addEdgetoVertex(int v1,int edgeIndex);
void addFacetoVertex(int v1,int faceIndex);

void createFace();

vertex vertices[50];
edge edges[20];
face faces[20];

void  input(){
	static const char filename[] = "input3.txt";
	FILE *file = fopen ( filename, "r" );
	

	if (file != NULL)
	{
		char line [ 128 ]; 
		int i;
			
		while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
			{
				if (line[0]=='#' || line[0]==' ' || line[0]=='\n'   ){
					continue;
				}
				else if(line[0]=='v'){
					float x,y,z;
					sscanf (line,"v %f,%f,%f ",&x, &y, &z);
					//~ printf("V[%d]: x= %4.2f, y= %4.2f, z= %4.2f \n",vIndex,x,y,z);
					createVertex(vIndex,x,y,z);
					vIndex++;
				}
				else if(line[0]=='f'){
					int v1,v2,v3,v4;
					sscanf (line,"f %d,%d,%d,%d ",&v1, &v2, &v3, &v4);
					//~ printf("Face found: v1= %d, v2= %d, v3=%d, v4=%d  \n",v1,v2,v3,v4);
					
					if (v1>vIndex || v2>vIndex || v3>vIndex || v4>vIndex )
					{
						//~ printf("Invalid Vertex Index \n");
					}
					else{
						//~ printf("BEFORE findex : %d, eIndex : %d\n",fIndex,eIndex);
						faces[fIndex].edge1=-1;
						faces[fIndex].edge2=-1;
						faces[fIndex].edge3=-1;
						faces[fIndex].edge4=-1;
						
						
						eIndex=createEdge(fIndex,1,eIndex,v1, v2);
						eIndex=createEdge(fIndex,2,eIndex,v2, v3);
						eIndex=createEdge(fIndex,3,eIndex,v3, v4);
						eIndex=createEdge(fIndex,4,eIndex,v4, v1);
						
						
						fIndex++;
						//~ printf("AFter findex : %d, eIndex : %d \n",fIndex,eIndex);
					}	
				}
				else {
					 //~ printf("INVALID LINE :  \t");
					 fputs ( line, stdout ); /* write the line */
				}
			}

			printf("INPUT COMPLETE \n \tVertices scanned:\t %d \n \t Faces Scanned: \t %d \n Edges Scanned:\t %d \n",vIndex,fIndex,eIndex);
			//~ printf("Face1 > %d, %d \n",edges[faces[1].edge3].vert1,edges[faces[1].edge3].vert2);
			fclose ( file );
	}
	else
	{
		perror ( filename ); /* why didn't the file open? */
	}
}

void createVertex(int i,float x,float y,float z){
	//~ printf("Create Vertex: \n");
	
	
	vertices[i].x=x;
	vertices[i].y=y;
	vertices[i].z=z;
	
	vertices[i].edge1=-1;
	vertices[i].edge2=-1;
	vertices[i].edge3=-1;
	vertices[i].edge4=-1;

	vertices[i].face1=-1;
	vertices[i].face2=-1;
	vertices[i].face3=-1;
	vertices[i].face4=-1;
	//~ printf("All SET \n");
}

int createEdge(int fIndex,int edgeFace, int edgeIndex,int v1, int v2){
	int i;

	//~ if (fIndex==1)
	{
		printf("V1 %d, V2 %d \n",v1, v2);
	}
	
	//~ printf("create Edge \n");
	//	printf("x1 %f, y1 %f, z1 %f, x2 %f, y2 %f, z2 %f \n",v1x,v1y,v1z,v2x,v2y,v2z);
	for (i=0;i<edgeIndex; i++){
		if((v1==edges[i].vert1 && v2==edges[i].vert2 )||(v2==edges[i].vert1 && v1==edges[i].vert2 )){
		switch(edgeFace){
			case(1):
			faces[fIndex].edge1=i;
			printf("Common Edge\n  EdgeIndex %d, FaceEdgeIndex %d, Vertex1 %d, Vertex2 %d \n",edgeIndex, faces[fIndex].edge1, edges[faces[1].edge1].vert1, edges[faces[1].edge1].vert2);
			break;

			case(2):
			faces[fIndex].edge2=i;
			printf("Common Edge\n  EdgeIndex %d, FaceEdgeIndex %d, Vertex1 %d, Vertex2 %d \n",edgeIndex, faces[fIndex].edge2, edges[faces[1].edge2].vert1, edges[faces[1].edge2].vert2);
			break;

			case(3):
			faces[fIndex].edge3=i;
			printf("Common Edge\n  EdgeIndex %d, FaceEdgeIndex %d, Vertex1 %d, Vertex2 %d \n",edgeIndex, faces[fIndex].edge3, edges[faces[1].edge3].vert1, edges[faces[1].edge3].vert2);
			break;

			case(4):
			faces[fIndex].edge4=i;
			printf("Common Edge\n  EdgeIndex %d, FaceEdgeIndex %d, Vertex1 %d, Vertex2 %d \n",edgeIndex, faces[fIndex].edge4, edges[faces[1].edge4].vert1, edges[faces[1].edge4].vert2);
			break;
		}
		//~ printf("Common Edge : vert1:%d vert2:%d \n ",v1,v2);
		//~ if (fIndex==1)
		
		
		return edgeIndex;
		}
	}
	edgeIndex++;
	addEdgetoVertex(v1,edgeIndex);
	addEdgetoVertex(v2,edgeIndex);

	addFacetoVertex(v1,fIndex);
	addFacetoVertex(v2,fIndex);

	edges[edgeIndex].vert1=v1;
	edges[edgeIndex].vert2=v2;

	switch(edgeFace){
		case(1):
		faces[fIndex].edge1=edgeIndex;
		printf("NEW Edge\n  EdgeIndex %d, FaceEdgeIndex %d, Vertex1 %d, Vertex2 %d \n",edgeIndex, faces[fIndex].edge1, edges[faces[1].edge1].vert1, edges[faces[1].edge1].vert2);
		break;

		case(2):
		faces[fIndex].edge2=edgeIndex;
		printf("NEW Edge\n  EdgeIndex %d, FaceEdgeIndex %d, Vertex1 %d, Vertex2 %d \n",edgeIndex, faces[fIndex].edge2, edges[faces[1].edge2].vert1, edges[faces[1].edge2].vert2);
		break;

		case(3):
		faces[fIndex].edge3=edgeIndex;
		printf("NEW Edge\n  EdgeIndex %d, FaceEdgeIndex %d, Vertex1 %d, Vertex2 %d \n",edgeIndex, faces[fIndex].edge3, edges[faces[1].edge3].vert1, edges[faces[1].edge3].vert2);
		break;

		case(4):
		faces[fIndex].edge4=edgeIndex;
		printf("NEW Edge\n  EdgeIndex %d, FaceEdgeIndex %d, Vertex1 %d, Vertex2 %d \n",edgeIndex, faces[fIndex].edge4, edges[faces[1].edge4].vert1, edges[faces[1].edge4].vert2);
		break;
		
		}
	//if (fIndex==1)
	{
	}

	return edgeIndex;
}


void addEdgetoVertex(int v,int e){
	//~ printf("in add edge e:%d, v:%d, edge1=%d, edge2=%d, edge3=%d, edge4=%d",e,v,vertices[v].edge1,vertices[v].edge2,vertices[v].edge3,vertices[v].edge4);	
	
	if (vertices[v].edge1==-1){
		vertices[v].edge1=e;
		//~ printf("E1 added to v no. %d \n",v);
	}
	else if (vertices[v].edge2==-1){
		vertices[v].edge2=e;
		//~ printf("E2 added to v no. %d \n",v);
	}
	else if (vertices[v].edge3==-1){
		vertices[v].edge3=e;
		//~ printf("E3 added to v no. %d \n",v);
	}
	else if (vertices[v].edge4==-1){
		vertices[v].edge4=e;
		//~ printf("E4 added to v no. %d \n",v);
	}
	else {
		printf("\t none added SOME ERROR\n");
	}
}

void addFacetoVertex(int v,int f){
		//~ printf("in add Face to vertex \n");	
	if (vertices[v].face1==-1){
		vertices[v].face1=f;
		//~ printf("F1 added to v no. %d \n",v);
	}
	else if (vertices[v].face2==-1){
		vertices[v].face2=f;
		//~ printf("F2 added to v no. %d \n",v);
	}
	else if (vertices[v].face3==-1){
		vertices[v].face3=f;
		//~ printf("F3 added to v no. %d \n",v);
	}
	else if (vertices[v].face4==-1){
		vertices[v].face4=f;
		//~ printf("F4 added to v no. %d \n",v);
	}
	else {
		//~ printf("\t none added SOME ERROR\n");
	}
}
