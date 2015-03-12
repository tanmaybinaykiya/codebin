#include<stdio.h>
#include<stdlib.h>

struct indexOf{
struct vertex *vert;
};

struct Vertex{
struct Vertex *next ;       
struct Vertex *prev ;       
};


void vertt()
{
struct indexOf *arr;
long int max=5;     //875714
arr=malloc (max * sizeof(struct indexOf));






getch();
  
}
int main()
{
 	FILE *fp;
 	if((fp = fopen("myGraph.txt", "r"))==NULL) 
    {
		printf("Cannot open file.\n");
		exit(0);
	}
	else
	{
         struct indexOf *indexO;
         long int max=21;     //875715;  ADD 1
         indexO=malloc ((max) * sizeof(struct indexOf));
         int i;
         for (i=1; i<max; i++){
             indexO[i].vert=NULL;
         }
         
         
		 char ch;
		 long int n,m;
		 
		 long int k;
		 for (k=1;k<max;k++)
		 {
		 	 fscanf(fp,"%d",&m);

		 	 if (indexO[m].vert==NULL)
                indexO[m].vert=malloc(sizeof(struct Vertex));

             fscanf(fp,"%d",&n);
		 	 printf("%d \n",n);
		 	 
		 	 
		 	 if (indexO[m].vert==NULL){
             indexO[m].vert=malloc(sizeof(struct Vertex));
             }
             else		 	 
		 	 if (indexO[n].vert==NULL)
		 	 indexO[n].vert=malloc(sizeof(struct Vertex));
		 	 
		 	 
		 }
		 
		 getch();
		 return 1; 	
    }
}
