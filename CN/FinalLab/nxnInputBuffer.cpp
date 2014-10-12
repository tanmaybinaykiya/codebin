// nxn switch with inp buffer
#include <iostream>     
#include <queue>    
#include <cstring>    
#include <cstdlib>     /* srand, rand */

#define MaxTime 50000
#define N 20

int main(){

	int i,j,k,m,nm;
	double sum=0,rn,thro,uni;
	
	for(i=1;i<=N;i++){
		int flag[i];
		memset (&flag,0,i);
		sum=0;
		for(j=0;j<MaxTime;j++){
			uni=0;
			std::queue<int> myqueue[i];
			for(k=0;k<i;k++){
				nm=rand() % i;  
				myqueue[k].push(nm);
				// std::cout<<"NM: "<<nm<<"\n";
			}
			for(m=0;m<i;m++){
				if(flag[myqueue[m].front()]==0)
				{
					flag[myqueue[m].front()]=1;	
					myqueue[m].pop();	
					uni=uni+1;
				}
			}
			for(m=0;m<i;m++){
				flag[m]=0;	
			}
			sum=sum+(uni/i);
		}
		
		thro=sum/MaxTime;
		std::cout<<"throughput of "<<i<<":"<<thro*100<< "% \n";
		
	}
}
