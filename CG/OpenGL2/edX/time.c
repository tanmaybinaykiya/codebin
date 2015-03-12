#include<stdio.h>
#include<time.h>
int main(){
	time_t start,end;
	volatile long unsigned t,u;
	start =time(NULL);
	for (u=0;u<50000;u++)
		for (t=0;t<50000;t++);
	end =time(NULL);
	printf("Loop used %f seconds \n",difftime(end,start));
}

