//NxN router switch fabric with input buffer
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<string.h>
#define SIZE 10000
#define N 100
#define m 1000
int *q[N];
void enq(int j,int *front,int *rear,int data,int *i){
	if((*rear)==-1){
		q[j]=(int *)malloc(SIZE*sizeof(int));
		*front=0;
		*rear=0;
		q[j][0]=data;
		*i=SIZE;
	}
	else if((*rear)!=(*i)*SIZE){
		(*rear)++;
		q[j][*rear]=data;
	}
	else{
		int *p,k;
		p=(int *)malloc(2*(*i)*sizeof(int));
		for(k=0;k<(*i)*SIZE;k++)
			p[k]=q[j][k];
		(*rear)++;
		p[*rear]=data;
		*i=2*(*i);
		q[j]=p;
	}
}
int deq(int j,int *front,int *rear){
	int ret;
	if((*rear)==-1)
		return -1;
	else if((*front)==(*rear)){
		ret=q[j][*front];
		free(q[j]);
		(*front)=-1;
		(*rear)=-1;		
		return ret;
	}
	else{
		int temp=*front;
		while(temp!=(*rear)){
			q[j][temp]=q[j][temp+1];
			temp++;
		}
		ret=q[j][*front];
		(*rear)--;
		return ret;
	}
}		
int main(){
	int front[N],rear[N],i,siz[N],rnd,j=0,k,temp,flag[N];
	float count=0,thru=0,tothru=0;
	srand(time(NULL));
	memset(rear, -1, sizeof(rear)); 
	memset(front, -1, sizeof(front));
	for(j=0;j<m;j++){ 
		memset(flag, 0, sizeof(flag)); 
		count=0;
		for(i=0;i<N;i++){
			rnd=rand()%N;
			enq(i,&front[i],&rear[i],rnd,&siz[i]);
		}
		for(i=0;i<N;i++){
			temp=deq(i,&front[i],&rear[i]);
			if(temp!=-1){
				if(flag[temp]==0){
					flag[temp]=1;
					count++;
				}
				else
					enq(i,&front[i],&rear[i],temp,&siz[i]);
			}		
		}
		thru=count/N;
		tothru+=thru;
	}
	tothru=tothru/m;
	printf("%0.2f\n",tothru);
	return 0;
}
