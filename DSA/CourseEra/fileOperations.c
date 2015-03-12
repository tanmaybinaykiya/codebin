#include<stdio.h>
#include<conio.h>
int main()
{
 	FILE *fp;
 	if((fp = fopen("IntegerArrayOriginal.txt", "r"))==NULL) 
    {
		printf("Cannot open file.\n");
		exit(0);
	}
	else
	{
		 char ch;
		 long int n;
		 long int i;
		 for (i=0;i<100000;i++)
		 {
		 	 fscanf(fp,"%d",&n);
		 	 printf("%d \n",n);
		 }
		 
		 getch();
		 return 1; 	
    }
}
