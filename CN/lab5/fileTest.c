#include <stdio.h>
#include <string.h>
int main(){
	FILE *img;
	char cwd[100] ="/home/tanmay/CN/lab6/";
	char fileName[]="temp.txt";
	strcat(cwd,fileName);
	img=fopen(cwd, "a+");
	if (img!=NULL)
	{
		fputs ("fopen example \n",img);
		fputs ("fopen example2 \n",img);
		fputs ("fopen example3 \n",img);
		fputs ("fopen example4 \n",img);
		close (img);
  	}

  	return 1;
}