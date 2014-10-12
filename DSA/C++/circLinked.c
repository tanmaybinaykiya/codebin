#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dLink{
	int val;
	char name[50];
	struct dLink *next;
	struct dLink *prev;
}typedef dLink;

dLink *head,*tail;

void push(int var,char nam[]){

	dLink *curr,*p,*n;

	if((head==tail)&&(tail==NULL)){
		//printf("HEY\n");
		head=(dLink *)malloc(sizeof(dLink));
		head->val=var;
		for(int i=0;i<50;i++){
			head->name[i]=nam[i];
		}	
		head->next=NULL;
		head->prev=NULL;
		tail=head;
	}
	else{
		curr=(dLink *)malloc(sizeof(dLink));
		curr->val=var;
		for(int i=0;i<50;i++){
			curr->name[i]=nam[i];
		}
		curr->prev=tail;
		curr->next=head;

		tail->next=curr;
		tail=curr;
	}
}

dLink pop(){
	dLink *newTail;

	printf("%d \t %s \n",tail->val, tail->name );
	tail->prev->next=head;
	newTail=tail->prev;
	free (tail);
	tail=newTail;

}

void printAll(void){
	dLink *curr;

	for(curr=head;curr->next!=head;curr=curr->next){
		printf("%d \t %s \n",curr->val, curr->name );
	}
	printf("%d \t %s \n---------------------------\n",curr->val, curr->name );

}

int main(){

	
	int max,i,var;
	char nam[50];

	scanf("%d",&max);
	head=tail=NULL;

	for (i = 0; i < max; ++i)
	{
		scanf("%d\t%s",&var,nam);
		push(var,nam);
	}

	printAll();
	pop();
	printAll();
	pop();
	printAll();
}