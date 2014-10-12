// nxn switch with output buffer
#include <stdio.h>     
#include <stdlib.h>     /* srand, rand */

#define MaxTime 50000
#define N 20

int main(){

	int i,j,k,m,nm;
	double sum=0,rn,thro,uni;
	
	for(i=1;i<=N;i++)
	{
		int a[i];
		int count[i];
		
		sum=0;
		for(j=0;j<MaxTime;j++)
		{
			uni=0;
			for(k=0;k<i;k++)
			{
				nm=rand() % i;  
				a[k]=nm;
				count[nm]++;
				
			}
			for(m=0;m<i;m++)
			{
				if(count[m]>0)
				{
					uni=uni+1;
					count[m]--;
				}
			}
			sum=sum+(uni/i);
		}
		
		thro=sum/MaxTime;
		printf("throughput of %d = %f \n",i,thro);
		
	}
}
