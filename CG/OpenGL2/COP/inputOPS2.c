
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
#include <ctype.h>
#include <ctype.h>
#include <time.h>
#include <sys/types.h>

int main ( void )
{
static const char filename[] = "data.txt";
FILE *file = fopen ( filename, "r" );
int i, j;
char arra[128][128];
char line[128]; /* or other suitable maximum line size */


for(i=0; i<128; i++)
for(j=0; j<128; j++)
arra[j] = '\0';

for(i=0; i<128; i++)
line = '\0';

if ( file != NULL )
{

i=0;

while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
{

strcpy(arra, line);
printf("array ----> %s ", &arra);
i++;

}
fclose ( file );
}
else
{
perror ( filename ); /* why didn't the file open? */
}


return 0;
}
