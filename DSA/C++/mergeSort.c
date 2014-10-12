#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
struct dLink{
	int val;
	char name[50];
	struct dLink *next;
	struct dLink *prev;
}typedef dLink;

void push(dLink **head,dLink **tail,int var,char nam[]){

	dLink *curr,*p,*n;

	if(((*head)==(*tail))&&((*tail)==NULL)){
		(*head)=(dLink *)malloc(sizeof(dLink));
		(*head)->val=var;
		for(int i=0;i<50;i++){
			(*head)->name[i]=nam[i];
		}	
		(*head)->next=NULL;
		(*head)->prev=NULL;
		(*tail)=(*head);
	}
	else{
		curr=(dLink *)malloc(sizeof(dLink));
		curr->val=var;
		for(int i=0;i<50;i++){
			curr->name[i]=nam[i];
		}
		curr->prev=(*tail);
		curr->next=NULL;

		(*tail)->next=curr;
		(*tail)=curr;
	}
}


dLink pop(dLink **tail){
	dLink *newTail;

	printf("%d \t %s \n",(*tail)->val, (*tail)->name );
	(*tail)->prev->next=NULL;
	newTail=(*tail)->prev;
	free (*tail);
	(*tail)=newTail;

}

void printAll(dLink *head){
	dLink *curr;

	for(curr=(head);curr->next!=NULL;curr=curr->next){
		printf("%d \t %s \n",curr->val, curr->name );
	
	}
	printf("%d \t %s \n---------------------------\n",curr->val, curr->name );

}
*dLink mergeSort(dLink *left,dLink *right){
	if(left==right){
		return left;
	}
	else{
		

	}

}

int main(){

	int max,i,var;
	char nam[50];
	dLink *head,*tail;

	scanf("%d",&max);
	head=tail=NULL;

	for (i = 0; i < max; ++i)
	{
		scanf("%d\t%s",&var,nam);
		push(&head,&tail,var,nam);
	}

	printAll(head);
	insertionSort(&head,&tail);
	printAll(head);	
}