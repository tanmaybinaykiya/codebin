/**************************************************************************************************
Problem Statement

Alice has a sweet tooth. She loves to eat chocolates. Alice's mom has made a rule that Alice can eat only one chocolate per day and that too in the morning. She has n chocolates initially. Each morning before going to school, she eats one chocolate. Every m-th day (at days with numbers m, 2m, 3m, ...), Alice's mom buys a chocolate for her. She does it late in the evening, so that Alice cannot eat a new chocolate before the next day. How many consecutive days pass until Alice runs out of chocolates?

Input

There are several test cases. Description for each test case - 
The single line contains two integers n and m, separated by a space.
"0 0" marks the end of the test cases.
Constraints

1 ≤ n ≤ 100
2 ≤ m ≤ 100
Output

Print a single integer — the answer to the problem.
Sample test(s)

Input
2 2
0 0
Output
3

Input
9 3
0 0
Output
13
Explanation

In the first sample for the first two days Alice eats the chocolate that she had initially. Then on day three she eats the chocolates that were bought on day two.

My Solution
**************************************************************************************************/
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
		if(currChocolates==0){
			cout<<i-1<<"\n";
			break;
		}
		currChocolates--;
		if(i%m==0)
			currChocolates+=1;
		i++;
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