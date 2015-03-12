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

};

struct edge{
	int vert1;
	int vert2;
	
	int face1;
	int face2;
	
	vertex v;
};

struct face{
	int vert1;
	int vert2;
	int vert3;
	int vert4;
	
	int edge1;
	int edge2;
	int edge3;
	int edge4;
	
	vertex v;
};

void createVertex(int v,float x,float y,float z);
void createFace();

vertex vertices[50];
edge edges[20];
face faces[20];

void  main(){
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
						faces[fIndex].edge2=-1;							//		Edges defaulted
						faces[fIndex].edge3=-1;							//
						faces[fIndex].edge4=-1;		

						faces[fIndex].vert1=v1;
						faces[fIndex].vert2=v2;							//			Vertices set
						faces[fIndex].vert3=v3;
						faces[fIndex].vert4=v4;
						
						eIndex=createEdge(fIndex,1,eIndex,v1, v2);
						eIndex=createEdge(fIndex,2,eIndex,v2, v3);		//			edges set
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



	return edgeIndex;
}


void addEdgetoVertex(int v,int e){
}

void addFacetoVertex(int v,int f){
}
