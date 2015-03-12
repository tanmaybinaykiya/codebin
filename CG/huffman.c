#include <stdio.h>
/*struct node 
{
	struct node* prev;
	char* code ;
	struct node* next;
};
void create_node (struct node* prev, char *s);
void generate();
*/
void input();
int main()
{
	int n;
	printf("Enter the number of alphabets");
	scanf("%d",&n);
	
	generate(n);	
	return 0;
}
/*void create_node (struct node* pre, char s[])
{
	struct node* curr;
	strcpy(curr->code, s);
	curr->next=NULL;
	curr->prev=pre;
}
void generate (int n)
{
    create_node(head,)
}
*/
