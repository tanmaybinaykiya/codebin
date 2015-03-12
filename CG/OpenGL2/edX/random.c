#include<stdio.h>
#define MAX 10000000

int main(){

	int freq[10]={0};
	float range[10]={0};
	int i=0;

	for (i=0;i<10;i++){
		range[i]=0.1+((float)(i)/10);
//		printf("range [%d] = %f \n",i,range[i]);
	}
	float n;
	for (i=0;i<MAX;i++){
		n=rand();
//		printf("%f \n",n);
		if(n>2150000000){
		printf("Greatest is %f",n);
		return(0);
		}

		n=n/2150000000;
//		printf("%f \n",n);
		if (n<range[0]){
			freq[0]++;}
		else if (n<range[1]){
			freq[1]++;}
		else if (n<range[2]){
			freq[2]++;}
		else if (n<range[3]){
			freq[3]++;}
		else if (n<range[4]){
			freq[4]++;}
		else if (n<range[5]){
			freq[5]++;}
		else if (n<range[6]){
			freq[6]++;}
		else if (n<range[7]){
			freq[7]++;}
		else if (n<range[8]){
			freq[8]++;}
		else if (n<range[9]){
			freq[9]++;}
		
	}
	int sum=0;
	for(i=0;i<10;i++){
		printf(" %d ,",freq[i]);
		sum=sum+freq[i];
	}	
	printf("\n MAX= %d, TOTAL = %d \n",MAX,sum);

return 1;
}
