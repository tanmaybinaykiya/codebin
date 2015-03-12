#include<stdio.h>
#include<stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void function(GLfloat*** vertArr ){
	int i,j,k;
	for (i=0;i<4;i++){
		for (j=0;j<4;j++){
			for (k=0;k<3;k++){
				printf("%f \n",vertArr[i][j][k]);
			}
		}		
	}
}

void main(){
	GLfloat  ***vertArr;
	int i,j,k;
	vertArr=(GLfloat ***)malloc(4*(sizeof(float**)));
	
	for(i=0;i<4;i++){
		vertArr[i]=(GLfloat **)malloc(4*(sizeof(float*)));
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
		vertArr[i][j]=(GLfloat *)malloc(3*(sizeof(float)));
		}
	}
	
	for (i=0;i<4;i++){
		for (j=0;j<4;j++){
			for (k=0;k<3;k++){
				vertArr[i][j][k]=i+j+k+3;
				
			}		
		}
	}	
	function(vertArr);

}
