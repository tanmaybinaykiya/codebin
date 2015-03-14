/**************************************************************************************************
Problem Statement

Shipra wants to impress her geeky boyfriend on Valentine's day. She wants to paint the wall of his house red with a number. She thinks that the larger the number is, there is more chance to impress him.

Unfortunately, she could only get v liters of paint. After doing some math, she concluded that digit d requires Pd liters of paint. Also, she knew that he doesn't like any 0's to be painted on his wall. That's why Shipra won't use them in her number at all.

Help her find the maximum number she can paint on the wall.

Input

The first line contains a positive integer v (0 ≤ v ≤ 10^6). 
The second line contains nine positive integers P1, P2, ..., P9 (1 ≤ Pi ≤ 10^5).
Output

Print the maximum number Shipra can paint. If he has too little paint for any digit (so, she cannot write anything), print -1.
Constraints :

1 <= v <= 100000

1 =< P[1...9] <= 100000

Example
INPUT

10
	5 5 5 5 5 5 5 5 5
OUTPUT
	99
***************************************************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
	using namespace std;

	long int find(std::vector<long int> paints, long int minUsageMaxNum){
	// cout<<"FIND : \t";
		for (long int i=paints.size()-1;i>=0;i--){
		// cout<<paints[i]<<"\t";
			if(paints[i]==minUsageMaxNum){
			// cout<<"\n";
				return i;
			}
		}
		cout<<"ERROR\n";
		return -1;
	}
	long int findNextPossible(std::vector<long int> paints,long int qty){
	// cout<<"FIND: "<<qty<<" \t";
		for(long int i=paints.size()-1;i>=0;i--){
		// cout<<paints[i]<<"\t";
			if(paints[i]<=qty){
			// cout<<"\n";
				return i;
			}
		}
	// cout<<"ERROR\n";
		return -1;

	}

	void solve(long int V, std::vector<long int> paints){
	// cout<<"SOLVE V:"<<V<<"\n";
		std::vector<long int> sortedPaint(paints);
		sort(sortedPaint.rbegin(),sortedPaint.rend());
		long int minUsageMaxNumPaintQuantity=sortedPaint[8];
		if(V<minUsageMaxNumPaintQuantity){
			cout<<"-1";
			return;
		}
	// cout<<"minUsageMaxNumPaintQuantity "<<minUsageMaxNumPaintQuantity<<"\n";
		long int minUsageMaxNum=find(paints,minUsageMaxNumPaintQuantity);
	// cout<<"minUsageMaxNum "<<minUsageMaxNum+1<<"\n";
		long int digits=V/(minUsageMaxNumPaintQuantity);
	// cout<<"digits "<<digits<<"\n";
		long int diff=V%(minUsageMaxNumPaintQuantity);
	// cout<<"diff "<<diff<<"\n";
		string output (digits, '1'+minUsageMaxNum);
	// cout<<"trivial output:"<<output<<" \n";
		long int charPosn=0;
	// cout<<"SOLVE5\n";
		while(diff!=0){
			if(charPosn>=output.size())
				break;
			long int nextPossible=findNextPossible(paints,minUsageMaxNumPaintQuantity+diff);
			if (nextPossible==-1){
				break;
			}
			else{		
				output[charPosn]=nextPossible + '1';
				diff-=paints[nextPossible]-paints[minUsageMaxNum];
			}
			charPosn++;
		}
		cout<<output<<endl;
	}

	int main(){
		long int V=0;
		std::vector<long int> paints(9,0);
		cin>>V;
		for(long int i=0;i<9;i++){
			cin>>paints[i];
		}

		solve(V,paints);
		return 0;
	}
