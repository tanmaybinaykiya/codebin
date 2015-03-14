/**************************************************************************************************
Problem Statement

You'll be given a number n, which would be followed by n lines of numbers A1, A2, .... , An.

If

Ai == 0 : You have to print the maximum amongst all the numbers seen till now.
Ai == -1 : Delete the last element. (i.e this element wouldn't be considered from now on)
Note that 0, -1, wouldn't be added to the pool of numbers which you are using to find the maximum or deletion.

Constraints

n <= 10^6
Ai <= 10^9
Input Format

First line would contain n, n lines would follow consisting of A1, A2 ... An. (One in each line)

Output Format

For each 0 encountered print the maximum element from the pool. (Ignoring 0 and -1 that you have seen).

For each -1 encountered delete the last element from the pool.

Note that the answer to each 0 and -1 queries should be printed in a new line.

Sample Input

10  
5
0
-1
10
7
0
12
0
-1
0
Sample Output

5
10
12
10

My Solution
**************************************************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;


int main() {
 /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
	long long int n;
	cin>>n;
	vector<long long int> arr;
	stack<long long int> myStack;
	myStack.push(-1);
	for(long long int i=0;i<n;i++){
		long long int temp;
		cin>>temp;
		if(temp==0){
			cout<<myStack.top()<<"\n";
		}
		else if(temp ==-1){
			if (arr[arr.size()-1]==myStack.top()){
				myStack.pop();
			}
			arr.pop_back();
		}else{
			arr.push_back(temp);
			if(myStack.top()<temp)
				myStack.push(temp);
		} 
	}
	return 0;
}
