#include <stdio.h>
struct edge{
	int v1;
	int v2;
}typedef edge;

struct vertex {
	edge *abc;
	}typedef vertex;
	
vertex c;	


void function(edge E){
	
	c.abc=&E;
	printf("%d %d \n",c.abc->v1,c.abc->v2);
}

int main (){

	//edge e1;
	//e1.v1=5;
	//e1.v2=7;

	//function(e1);
	
	int A=5,B=7;
	
	A=A+B-(B=A);
	
	printf("%d , %d",A,B);

}
