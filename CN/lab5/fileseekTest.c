#include <stdio.h>
#include <string.h>
int main(){

	FILE *img;
	img=fopen("myFilename",  "r");

	char *ptr=(char *)img;

	printf(" %s",ptr);

	fclose(img);
	return 1;
}