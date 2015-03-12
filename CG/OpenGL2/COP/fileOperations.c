#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
 	FILE *fp;
 	if((fp = fopen("input.txt", "r"))==NULL) 
    {
		printf("Cannot open file.\n");
		exit(0);
	}
	else
	{
		 char ch;
		 float n;
		 int i;
		 //String a;
		 
		 
		 for (i=0;i<10;i++)
		 {
		 	 fscanf(fp,"%f",&n);
		 	 printf("%f \n",n);

		 }
		 
		 
		 
		 //getch();
		 return 1; 	
    }
}
