#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void compute(int n, int m){
	// cout<<"COMPUTE";
	int currChocolates=n;
	int i=0;
	while(1){		
		// cout<<"WHILE";
		i++;
		if(currChocolates==0){
			cout<<i-1<<"\n";
            break;
		}
        currChocolates--;
		if(i%m==0)
			currChocolates++;
	}
}

int main(){
	int n,m;
	while(1){
		cin>>n;
		cin>>m;
		if(n==0 && m==0)
			break;
		compute(n,m);
	}

	return 0;
}