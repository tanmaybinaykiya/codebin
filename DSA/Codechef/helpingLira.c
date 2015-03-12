#include <stdio.h>
int main(){
	int minIndex=0,maxIndex=0;
	int minVal,maxVal,i=0,n=0,x1,y1,x2,y2,x3,y3;

	scanf("%d\n",&n);

	for(i=0;i<n;++i){
		scanf("%d %d %d %d %d %d ",&x1,&y1,&x2,&y2,&x3,&y3);
		int area=(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
		area=(area<0)? -area:area;
		if(i==0){
			maxVal=minVal=area;
		}
		else{
			if(area<=minVal){
				minVal=area;
				minIndex=i;
			}
			if(area>=maxVal){
				maxVal=area;
				maxIndex=i;
			}
		}
	}
	printf("%d %d\n",minIndex+1,maxIndex+1);
	return 0;
}
