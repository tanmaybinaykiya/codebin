#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
//#include "doosabin.c"
//#include "catmullclark.c"
_Bool smooth;


//****************************************************

// input filename hardocoded into code
// input file line size should not exceed 128 characters
//			  line starting with ' ' or '#'  is treated as a comment
//			  line starting with v should contain 3 parameters (x, y, z)seperated by a ','character. 
//			  line starting with f should contain 4 parameters (vertex1, vertex2, vertex3, vertex4) all in the clockwise order seperated by a ','character




const int maxVertices=50;
const int maxEdges=50;
const int maxFaces=15;

int vIndex=0, eIndex=0, fIndex=0;



//~ void subdivide()
//~ {
//~ }
//~ void showSubdiv()
//~ {
	//~ int i;
	//~ for(i=0;i<fIndex;i++)
	//~ {
		//~ 
		//~ glBegin(GL_LINE_STRIP);
			//~ 
		//~ glEnd();
	//~ }
	//~ 
//~ }
//~ 
//~ 
//~ 
//~ 



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
	static const char filename[] = "input5.txt";
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

		//	printf("INPUT COMPLETE \n \tVertices scanned:\t %d \n \t Faces Scanned: \t %d \n Edges Scanned:\t %d \n",vIndex,fIndex,eIndex);
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
	//	printf("V1 %d, V2 %d \n",v1, v2);
	}
	
	//~ printf("create Edge \n");
	//	printf("x1 %f, y1 %f, z1 %f, x2 %f, y2 %f, z2 %f \n",v1x,v1y,v1z,v2x,v2y,v2z);
	for (i=0;i<edgeIndex; i++){
		if((v1==edges[i].vert1 && v2==edges[i].vert2 )||(v2==edges[i].vert1 && v1==edges[i].vert2 )){
		switch(edgeFace){
			case(1):
			faces[fIndex].edge1=i;
		//	printf("Common Edge\n  EdgeIndex %d, FaceEdgeIndex %d, Vertex1 %d, Vertex2 %d \n",edgeIndex, faces[fIndex].edge1, edges[faces[1].edge1].vert1, edges[faces[1].edge1].vert2);
			break;

			case(2):
			faces[fIndex].edge2=i;
		//	printf("Common Edge\n  EdgeIndex %d, FaceEdgeIndex %d, Vertex1 %d, Vertex2 %d \n",edgeIndex, faces[fIndex].edge2, edges[faces[1].edge2].vert1, edges[faces[1].edge2].vert2);
			break;

			case(3):
			faces[fIndex].edge3=i;
		//	printf("Common Edge\n  EdgeIndex %d, FaceEdgeIndex %d, Vertex1 %d, Vertex2 %d \n",edgeIndex, faces[fIndex].edge3, edges[faces[1].edge3].vert1, edges[faces[1].edge3].vert2);
			break;

			case(4):
			faces[fIndex].edge4=i;
		//	printf("Common Edge\n  EdgeIndex %d, FaceEdgeIndex %d, Vertex1 %d, Vertex2 %d \n",edgeIndex, faces[fIndex].edge4, edges[faces[1].edge4].vert1, edges[faces[1].edge4].vert2);
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
	//	printf("NEW Edge\n  EdgeIndex %d, FaceEdgeIndex %d, Vertex1 %d, Vertex2 %d \n",edgeIndex, faces[fIndex].edge1, edges[faces[1].edge1].vert1, edges[faces[1].edge1].vert2);
		break;

		case(2):
		faces[fIndex].edge2=edgeIndex;
		//printf("NEW Edge\n  EdgeIndex %d, FaceEdgeIndex %d, Vertex1 %d, Vertex2 %d \n",edgeIndex, faces[fIndex].edge2, edges[faces[1].edge2].vert1, edges[faces[1].edge2].vert2);
		break;

		case(3):
		faces[fIndex].edge3=edgeIndex;
	//	printf("NEW Edge\n  EdgeIndex %d, FaceEdgeIndex %d, Vertex1 %d, Vertex2 %d \n",edgeIndex, faces[fIndex].edge3, edges[faces[1].edge3].vert1, edges[faces[1].edge3].vert2);
		break;

		case(4):
		faces[fIndex].edge4=edgeIndex;
		//printf("NEW Edge\n  EdgeIndex %d, FaceEdgeIndex %d, Vertex1 %d, Vertex2 %d \n",edgeIndex, faces[fIndex].edge4, edges[faces[1].edge4].vert1, edges[faces[1].edge4].vert2);
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
	//	printf("\t none added SOME ERROR\n");
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
//********************************************************




void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_SMOOTH);
	GLfloat white[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 80.0f);
    
    GLfloat light_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 0.0, 0.0,1.0 }; 
    GLfloat light_specular[] = { 1.0, 1.0, 1.0,1.0};
    GLfloat light_position[] = { 4.0, 2.0, 3.0, 0 }; 
       
    glLightfv (GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv (GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv (GL_LIGHT0, GL_SPECULAR, light_specular); 
    glLightfv (GL_LIGHT0, GL_POSITION, light_position); 
  
   
   glEnable (GL_LIGHTING); 
   glEnable (GL_LIGHT0);
}
void showOriginal(){
	int i=0;
	//glColor3f(1,1,0);
	for (i=0;i<fIndex ;i++)
	{
		//If the DIAGONALS intersect inside the quad, draw, or swap the edge
		float v1x=vertices[edges[faces[i].edge1].vert1].x;
		float v1y=vertices[edges[faces[i].edge1].vert1].y;
		float v1z=vertices[edges[faces[i].edge1].vert1].z;

		float v2x=vertices[edges[faces[i].edge1].vert2].x;
		float v2y=vertices[edges[faces[i].edge1].vert2].y;
		float v2z=vertices[edges[faces[i].edge1].vert2].z;

		float v3x=vertices[edges[faces[i].edge3].vert1].x;
		float v3y=vertices[edges[faces[i].edge3].vert1].y;
		float v3z=vertices[edges[faces[i].edge3].vert1].z;

		float v4x=vertices[edges[faces[i].edge3].vert2].x;
		float v4y=vertices[edges[faces[i].edge3].vert2].y;
		float v4z=vertices[edges[faces[i].edge3].vert2].z;

	//	printf("\nBefore setting t \n");
	//	printf("vx %4.2f, vy %4.2f, vz %4.2f, ax %4.2f,bx %4.2f,cz %4.2f \n",v1x,v1y,v1z,v2x,v2y,v2z);
	//	printf("vx %4.2f, vy %4.2f, vz %4.2f, ax %4.2f,bx %4.2f,cz %4.2f \n ",v3x,v3y,v3z,v4x,v4y,v4z);

		int parallel=1;

		float tx;
		if(v1x!=v4x){
			tx=(v2x-v3x)/(v1x-v4x);
			if(tx!=-1)
			{
				tx=tx/(1+tx);
			}
			else{
				parallel*=-1;
			}
		}
		else{
			tx=-1;
			parallel*=-1;
		}
		float ty;
		if(v1y!=v4y){
			tx=(v2y-v3y)/(v1y-v4y);
			if(ty!=-1)
			{
				ty=ty/(1+ty);
			}
			else{
				parallel*=-1;
			}
		}
		else{
			ty=-1;
			parallel*=-1;
		}
		
		float tz;
		if(v1z!=v4z){
			tx=(v2z-v3z)/(v1z-v4z);
			if(tz!=-1)
			{
				tz=tz/(1+tz);
			}
			else{
				parallel*=-1;
			}
		}
		else{
			tz=-1;
			parallel*=-1;
		}

		
	//	printf("\nT : tx %f, ty %f, tz %f \n",tx,ty,tz);

	//	glColor3f(1-(float)i/5,1-(float)i/5,0);
	//glColor3f(1,0,0);
		glBegin(GL_LINE_LOOP);
		if ((parallel==-1)||((0<=tx && tx<1) && (0<=ty && ty<1) && (0<=tz && tz<1)))
			{
			//	printf("\n  t between 0 and 1 \n");
				//~ printf("vx %f, vy %f, vz %f, ax %f,bx %f,cx %f \n",v1x,v1y,v1z,v2x,v2y,v2z);
				//~ printf("vx %f, vy %f, vz %f, ax %f,bx %f,cx %f \n ",v3x,v3y,v3z,v4x,v4y,v4z);
				glVertex3f(v1x,v1y,v1z);
				glVertex3f(v2x,v2y,v2z);
				
				glVertex3f(v3x,v3y,v3z);
				glVertex3f(v4x,v4y,v4z);
				glVertex3f(v1x,v1y,v1z);
			}
			else{ 
			//	printf("\n \t Outside 0 and 1 \n");
				//~ printf("\t vx %f, vy %f, vz %f, ax %f,bx %f,cx %f \n",v1x,v1y,v1z,v2x,v2y,v2z);
				//~ printf("\t vx %f, vy %f, vz %f, ax %f,bx %f,cx %f \n ",v3x,v3y,v3z,v4x,v4y,v4z);
				//~ printf("\n -------------\n");
				glVertex3f(v1x,v1y,v1z);
				glVertex3f(v2x,v2y,v2z);
				
				glVertex3f(v3x,v3y,v3z);
				glVertex3f(v4x,v4y,v4z);
				glVertex3f(v1x,v1y,v1z);
				
			}
		
		glEnd();
	}

}
void showAxis(){
	glColor3f(1,1,1);
	glBegin(GL_LINES);

		glVertex3f(0,0,0);
		glVertex3f(10,0,0);

		glVertex3f(0,0,0);
		glVertex3f( 0,10,0);

		glVertex3f(0,0,0);
		glVertex3f(0,0,10);

	glEnd();		

} 

void doosabin()
{
     float origVert[fIndex][4][3];
     float newVert [fIndex][4][3];
     float W[4][4];
    
     int i=0, j=0, k=0;
     
     for(k=0; k<fIndex; k++)
     {
        origVert[k][0][0]= vertices[edges[faces[k].edge1].vert1].x;
        origVert[k][0][1]= vertices[edges[faces[k].edge1].vert1].y;
        origVert[k][0][2]= vertices[edges[faces[k].edge1].vert1].z;

        origVert[k][1][0]= vertices[edges[faces[k].edge1].vert2].x;
        origVert[k][1][1]= vertices[edges[faces[k].edge1].vert2].y;
        origVert[k][1][2]= vertices[edges[faces[k].edge1].vert2].z;
        
        origVert[k][2][0]= vertices[edges[faces[k].edge3].vert1].x;
        origVert[k][2][1]= vertices[edges[faces[k].edge3].vert1].y;
        origVert[k][2][2]= vertices[edges[faces[k].edge3].vert1].z;
        
        origVert[k][3][0]= vertices[edges[faces[k].edge3].vert2].x;
        origVert[k][3][1]= vertices[edges[faces[k].edge3].vert2].y;
        origVert[k][3][2]= vertices[edges[faces[k].edge3].vert2].z;        
        }
        
////CALCULATING
for(k=0; k<fIndex; k++)
{
      // glBegin(GL_POLYGON);
        
        for (i=0; i<4; i++)
        {
            newVert[k][i][0] = 0;
            newVert[k][i][1] = 0;
            newVert[k][i][2] = 0;
            
            
            for(j=0; j<4; j++)
            {
                    W[i][j] = (3 + (2 * cos(2*3.14*(i-j)/4))) / (4*4);
                    newVert[k][i][0] = newVert[k][i][0] + W[i][j] * origVert[k][j][0];
                    newVert[k][i][1] = newVert[k][i][1] + W[i][j] * origVert[k][j][1];
                    newVert[k][i][2] = newVert[k][i][2] + W[i][j] * origVert[k][j][2];                    
            }
            
           // glVertex3f(newVert[k][i][0],newVert[k][i][1],newVert[k][i][2]);         
                       
        }
        
       // glEnd();
}


///PRINTING FACES
int point=1;
for(k=0; k<fIndex; k++)
{
        glBegin(GL_LINE_LOOP);
        
        for (i=0; i<4; i++)
        {
        glVertex3f(newVert[k][i][0],newVert[k][i][1],newVert[k][i][2]);
                 
        printf("\nPoint %d : %f %f %f",point++, newVert[k][i][0],newVert[k][i][1],newVert[k][i][2]);  
//        getch();           
        }
        glEnd();
}

}
                    


void display(void){
	int i;
	glClear (GL_COLOR_BUFFER_BIT);
//	glFrontFace(GL_CW);

//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_BACK);

	glRotatef(1,0,1,0.1);
	//glRotatef(1,1,0,0);
	
	showAxis();

	if (!smooth){
		showOriginal();
	}
	else {
		//showSubdiv();
		doosabin();
	}

	glutSwapBuffers();
	usleep(10000);
	glutPostRedisplay();
}

void keyboard (unsigned char key, int x, int y)
{
	switch (key) {
		case 27:
			exit(0);
			break;
		case 'n':
			smooth=!smooth;
			glutPostRedisplay();
			break;

	}
}
void reshape (int w, int h)
{
	glViewport (0,0,(GLsizei) w,(GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 1000.0);
	gluLookAt(0,5,5,0,0,0,0,1,0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glScalef(0.2,.2,.2);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();
	input();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
