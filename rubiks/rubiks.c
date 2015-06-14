#include <stdio.h>

#define RED 1;
#define GREEN 2;
#define BLUE 3;
#define YELLOW 4;
#define WHITE 5;
#define BLACK 6;

struct face;
struct corner;
struct edge;

struct face{
	int color;
	struct edge *left,*right,*top,*bottom;
};

struct edge{
	int color1,color2;
	struct edge *left, *right;
	struct face *top,*bottom;
}typedef edge;

struct corner{
	int color1,color2,color3;
	struct edge *x, *y, *z;
}typedef corner;

int main(){
	face faces[6];
	corner corners[8];
	edge edges[12];

	face[0].color = RED;		
		edge[0].color1=RED;		//bottom left right top 
		edge[1].color2=RED;
		edge[2].color1=RED;
		edge[3].color2=RED;

	face[1].color = GREEN;
		edge[3].color1=GREEN;
		edge[4].color2=GREEN;
		edge[5].color1=GREEN;
		edge[6].color2=GREEN;

	face[2].color = BLUE;
		edge[6].color1=BLUE;
		edge[7].color2=BLUE;
		edge[8].color1=BLUE;
		edge[9].color2=BLUE;

	face[3].color = YELLOW;
		edge[9].color1=YELLOW;
		edge[10].color2=YELLOW;
		edge[11].color1=YELLOW;
		edge[0].color2=YELLOW;

	face[4].color = WHITE;
		edge[].color1 = WHITE;
		edge[].color2 = WHITE;
		edge[].color1 = WHITE;
		edge[].color2 = WHITE;

	face[5].color = BLACK;

	face[0].left	= &edge[0]; 	edge[0].bottom	= &face[0];
	face[0].right 	= &edge[1]; 	edge[1].top		= &face[0];
	face[0].top		= &edge[2];		edge[2].bottom	= &face[0];
	face[0].bottom	= &edge[3];		edge[3].top		= &face[0];

	face[]

	return 0;
}

