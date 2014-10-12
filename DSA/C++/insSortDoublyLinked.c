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

void insertElement(dLink **head,dLink **ele){
	dLink *ptr,*elem;
	elem=*ele;

	for(ptr=(*head);ptr->next!=(*ele);ptr=ptr->next){
		if(	(	(ptr->val) <= (	(*ele)->val) )	&&	(	((ptr->next)->val) > (	(*ele)->val)	)	){
			
			elem->prev->next=elem->next;
			
			if (elem->next!=NULL){
				elem->next->prev=elem->prev;
			}	
			
			elem->prev=ptr;
			elem->next=ptr->next;
			
			ptr->next->prev=elem;
			ptr->next=elem;
			break;
		}
		else if(	(*head)->val > elem->val){
			elem->prev->next=elem->next;
			elem->next->prev=elem->prev;

			elem->next=(*head);
			elem->prev=NULL;

			*head=elem;
			break;
		}
	}	
}

void insertionSort(dLink **left, dLink **right){
	if((*left)!=(*right)){
		insertionSort(left,&((*right)->prev));
		insertElement(left,right);
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