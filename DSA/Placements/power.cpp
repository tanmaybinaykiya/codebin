#include <cmath>
#include <cstdio>
#include <map>
#include <iostream>
using namespace std;
map<long long, long long> powers;


long long pow(long long a,long long b){	
	if(powers.find(b)!=powers.end()){
		return powers[b];
	}
	else{
		if(b%2==0){
			powers[b]=pow(a,b/2)*pow(a,b/2);
			return powers[b];
		}
		else{
			powers[b]=pow(a,b/2+1)*pow(a,b/2);
			return powers[b];
		}
	}
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int i,numTest;
	cin>>numTest;
	for(i=0;i<numTest;i++){
		long long n,m;
		cin>>n;
		cin>>m;
		powers.clear();
		powers[0]=1;
		powers[1]=n;
		long long result=pow(n,m);
		cout<<result<<"\n";
	}
	return 0;
}
