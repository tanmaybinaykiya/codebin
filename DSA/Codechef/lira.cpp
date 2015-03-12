#include <iostream>
#include <cmath>
int main(){
	
	float minValue=0,maxValue=0;
	int i,m,minIndex=0,maxIndex=0,x1,x2,x3,y1,y2,y3;;

	std::cin>>m;
	for (i=0;i<m;i++){
		std::cin>>x1;
		std::cin>>y1;
		std::cin>>x2;
		std::cin>>y2;
		std::cin>>x3;
		std::cin>>y3;

		float a=(float)sqrt( pow((x1-x2),2) + pow((y1-y2),2) );
		float b=(float)sqrt( pow((x2-x3),2) + pow((y2-y3),2) );
		float c=(float)sqrt( pow((x3-x1),2) + pow((y3-y1),2) );
		float s=(float)(a+b+c)/2;
		float area=(float)sqrt( s* (s-a) * (s-b) * (s-c) );

		if(i==0){
			minValue=area;
			maxValue=area;
			minIndex=0;
			maxIndex=0;
		}
		
		if(minValue>=area){
			minIndex=i;
			minValue=area;
		}

		if(maxValue<=area){
			maxIndex=i;
			maxValue=area;
		}
	}
	std::cout<<minIndex+1<<" "<<maxIndex+1<<"\n";
}