#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
#include <time.h>
///ANSWER 2407905288
struct arr 
{
       struct arr *next;
       long int value;
};
unsigned long long int mergeCount=0;
unsigned long long int splitCount=0;

unsigned long long int MAX=100000;
void insert(struct arr *head, int v)
{
       struct arr *temp,* curr;
       temp=(struct arr *)malloc(sizeof(struct arr));
       temp->value=v;
       temp->next=NULL;
	   curr=head;
       while(curr->next!=NULL)
	       	curr=curr->next;
       curr->next=temp;
}

struct arr* del(struct arr *head, int v)
    {
        struct arr *curr;
        int flag;
        flag=0;
        curr=head;

        if ((curr->value)== v)
        {
           flag=1;
           return(curr->next);
        }
        while (1)
        {
              if ((curr->next->value)==v)
              {
                  curr->next=curr->next->next;
                  flag=1;
                  return head;
              }                                     
              curr=curr->next;
              if (curr==NULL)
              {   
                  break;
              }    
        }
        if (flag==0)
        {
            printf("Error in node deletion");
        }         
} 

void printlist(struct arr *head)
    {
         struct arr *curr;
         curr=head;
         while((curr->next)!=NULL)
         {
             printf("%d \t",curr->value);
             curr=curr->next;
         }     
         printf("%d \t \n",curr->value);
    }

int sizelist(struct arr *head)
    {
        int n=1;
        struct arr *curr;
        curr=head;

        while((curr->next)!=NULL)
        {
        curr=curr->next;                              
            n++;
        }
        return n;
    }
struct arr * mergeSortMerge(struct arr *sleft,struct arr *sright, struct arr *merged,unsigned long int size,unsigned long int lsize )
{

///	   Merge 
       long int flag=0,i;
 	   struct arr *temp;	   
	   temp=(struct arr *)malloc(sizeof(struct arr));
	   temp->next=NULL;
	   temp->value=0;
	   merged=temp;
	   
	   mergeCount=0;
	   long int counter=0;
	   for (i=1;i<size;i++)
	   {
	   	   insert(temp,0);
   		   if (flag==0)
		   {	   
		   		   if((sleft->value)<(sright->value))
			   	   {
					    temp->value=sleft->value;
					    temp=temp->next;
					    lsize--;
					    if (lsize<0)
					       printf("%ld",lsize);
						if ((sleft->next)!=NULL)
						     sleft=sleft->next;
						else 
							 flag=1;
				   }
			   	   else
			   	   {
				   	    mergeCount=mergeCount+lsize;
				   	    if (mergeCount<0)
				   	       printf("mergeCount =%ld lsize=%ld \n",mergeCount,lsize);
					    temp->value=sright->value;
					    temp=temp->next;
						if ((sright->next)!=NULL)
						{
							sright=sright->next;
					    }	 
						else 
						{
							flag=2;
					    }
				   }
           }
   		   else if (flag==1)
		   {

		   		temp->value=sright->value;
		   		temp=temp->next;
		        sright=sright->next;
		   } 			   
   		   else if (flag==2)
		   {
		   		temp->value=sleft->value;
		   		temp=temp->next;
		   		sleft=sleft->next;		 				
		   }
	   }
	   
	   if (flag==1)
		   temp->value=sright->value;
	   else if (flag==2)
	   {
		   temp->value=sleft->value;		   
	   }	   
	return merged;	   
}	

struct arr * mergeSortS(struct arr *merged,long long int size)
{
///    Split 
	   
 	   if (size==1)
 		   return merged;

 	   long long int lsize,i,k,flag;
 	   struct arr *left,*right,*sleft,*sright,*temp;
   	   lsize=(size+1)/2;

	   temp=merged;
 	   for (i=1;i<lsize;i++)
 	   	   temp=temp->next;

       right=temp->next;
       temp->next=NULL;
   	   left=merged;
   	   	   
	   sleft=mergeSortS(left,lsize);
	   sright=mergeSortS(right,(size-lsize));
	   merged=mergeSortMerge(sleft,sright,merged,size,lsize);
	   splitCount+=mergeCount;
	   if (splitCount<0)
	   	  printf("Split count = %ld merge Count=%ld",splitCount,mergeCount);
	   return merged;
}
void userInput()
{
        printf("Enter the numbers. Insert 0 to exit \n");                     
        long int count=0,n=0;
        struct arr *head,*shead, *final, *curr;
        head=(struct arr *)malloc(sizeof(struct arr));
        head->next=NULL;
        head->value=0;

        while(scanf("%d",&n), n != 0 )
        {
            if (count==0)
            {
                  head->value=n;
                  count=1;
                  curr=head;
            }
            else
            {
                  insert(head,n);
                  count++;
            }
        }
	        printlist(head);
	        final=mergeSortS(head,count);
	        printf("SORTED LIST : \n");   
	        printlist(final);             
	        printf("INVERSIONS : %d \n",splitCount);   
			
        getchar();
        
}
void fileInput()
{
 	FILE *fp;

 	if((fp = fopen("IntegerArrayOriginal.txt", "r"))==NULL) 
    {
		printf("Cannot open file.\n");
		exit(0);
	}
	else
	{
 	 	char ch;
        long int n,i;
        struct arr *head,*sorted;
        head=(struct arr *)malloc(sizeof(struct arr));
        head->next=NULL;
        head->value=0;
		 
		for (i=0;i<MAX;i++)
		{
	        fscanf(fp,"%d",&n);
            if (i==0)
                  head->value=n;
            else
                  insert(head,n);
		}
		
  		sorted=mergeSortS(head,MAX);
//	    printf("SORTED LIST : \n");   
		
//	    printlist(sorted);             
        printf("INVERSIONS : %ll \n",splitCount);   
        printf("INVERSIONS : %llu \n",splitCount);   

		
    }
}
int main()
{
 	 fileInput();
	 return 1;
}
