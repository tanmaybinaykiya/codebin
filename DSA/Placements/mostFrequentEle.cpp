/**************************************************************************************************
Given a list of N numbers, print the most frequent element.

Note : If the frequency of some elements is same, then print the smallest of them.

Constraints :

N <= 10^5
Every element of the list is less than 10^9 and greater than 0.
Input Format

The first line consists of N, the number of elements in the list. N lines follow, each containing one element.

Output Format

Just print the most frequent element.

Sample Input

6
4
2
5
5
2
4
Sample Output

2
Explanation

All the six elements are have the same frequency, hence we print the smallest of them i.e '2'.

My Solution::
**************************************************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
/* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
	long int n;
	cin>>n;
	vector<long int> arr;
//cout<<"HIII1";

	for(long int i=0;i<n;i++){
		long int temp;
		cin>>temp;
		arr.push_back(temp);
	}
	sort(arr.begin(),arr.end());
//cout<<"HIII2";
	long int oldMaxCount=0,currCount=0,oldMax=0,curr=arr[n-1]-1;
//cout<<"HIII3";

	for(long int i=n-1;i>=0;i--){
		if(arr[i]!=curr){
			if(oldMaxCount<=currCount){
				oldMaxCount=currCount;
				oldMax=curr;
			}
			curr=arr[i];
			currCount=1;
		}
		else{
			currCount++;
		}

	}
	if(oldMaxCount<=currCount){
		oldMaxCount=currCount;
		oldMax=curr;
	}
	cout<<oldMax<<"\n";
	return 0;
}