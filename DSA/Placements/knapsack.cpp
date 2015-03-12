#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX(a,b)(a>b)?a:b

int main() {
	int bagCapacity,itemCount;
	vector<int> weight,value;
	cin>>bagCapacity;
	cin>>itemCount;
	for(int i=0;i<itemCount;i++){
		int cap,val;
		cin>>cap;
		cin>>val;
		weight.push_back(cap);
		value.push_back(val);
	}
	vector<int> temp(bagCapacity+1,0);
	vector< vector<int> > myTable;
	for(int i=0;i<itemCount+1;i++){
		myTable.push_back(temp);
	}
	
	for(int decideItemNum=0;decideItemNum<=itemCount;decideItemNum++){
		for(int allowedWeight=0;allowedWeight<=bagCapacity;allowedWeight++){
			if(allowedWeight==0 || decideItemNum==0){
				myTable[decideItemNum][allowedWeight]=0;
			}
			else{
				if(allowedWeight>weight[decideItemNum-1]){
					myTable[decideItemNum][allowedWeight]=MAX(myTable[decideItemNum-1][allowedWeight-weight[decideItemNum-1]] + value[decideItemNum-1],  myTable[decideItemNum-1][allowedWeight]);
				}
				else{
					myTable[decideItemNum][allowedWeight]=myTable[decideItemNum-1][allowedWeight];
				}
			}
		}
	}
	cout<<myTable[itemCount][bagCapacity]<<"\n";
	return 0;
}
