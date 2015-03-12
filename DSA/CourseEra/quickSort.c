#include<stdio.h>
#include<stdlib.h>
# define MAX 6
void quickSort(int arr[],int p,int r){
    int q=0;
    printf("qs \n");
	if (p<r){
	    q=partition(arr,p,r);
	    quickSort(arr,p,q);
	    quickSort(arr,q+1,r);
	}
}
int partition(int arr[],int p,int r){
	int x=arr[p];  //FIRST ELEMENT

	int i,j,temp=0;
	i=p-1;
	j=r+1;
    printf("prtn \n");
	
	while(1){
	    if(arr[j]<x)
  			j--;
    printf("prtn wh1\n");

  		if(arr[i]>x)
  			i++;

    printf("prtn wh2\n");

  		if (i<j){
		    temp=arr[i];
		    arr[i]=arr[j];
		    arr[j]=temp;
    		printf("prtn if\n");

		}
		else {
            printf("%d \n",arr[j]);
            return j;   	
            break;
		}
 	}   
}
int main(){
	
	int array[]={5,7,8,1,6,2};
	int size,i;
	size=MAX;
	for (i=0;i<MAX;i++){
		printf("%d \t",array[i]);
	}
	
	printf("\n ");
	
	quickSort(array,0,MAX-1);
	
	printf("\n HUGAGAG");
	for (i=0;i<MAX;i++){
		printf("%d \t",array[i]);
	}
	getch();
	return 1;
}


