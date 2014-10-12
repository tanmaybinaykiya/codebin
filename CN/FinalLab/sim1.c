#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000
int N=2;
int *enq(int q[],int *front,int *rear,int data,int *i){
	if((*rear)==-1){
		q=(int *)malloc(SIZE*sizeof(int));
		*front=0;
		*rear=0;
		q[0]=data;
		return q;
	}
	else if((*rear)!=(*i)*SIZE){
		(*rear)++;
		q[*rear]=data;
		return q;
	}
	else{
		int *p,k;
		p=(int *)malloc(2*(*i)*SIZE*sizeof(int));
		for(k=0;k<(*i)*SIZE;k++)
			p[k]=q[k];
		(*rear)++;
		p[*rear]=data;
		return p;
	}
}
int main(){
	int *q1,front[N],rear[N],i,siz[N];
	for(i=0;i<N;i++)
		rear[i]=-1;
	for(i=0;i<10;i++)
		q1=enq(q1,&front[0],&rear[0],i,&siz[0]);
	while(front[0]!=rear[0])
		printf("%d",q1[front[0]++]);
	printf("%d",q1[front[0]]);
	return 0;
}
		
		
		
