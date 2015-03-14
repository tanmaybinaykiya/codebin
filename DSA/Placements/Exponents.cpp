/**************************************************************************************************
Problem Statement

Use recursion and write a function that implements the power function, x^n.

Hint: Pay attention to time and input constraints!

Input Format

The first line has the number of test cases, say t (0 ≤ t ≤ 10^5).

The next t lines contain two integers, x (0 ≤ x ≤ 100) and n (0 ≤ n ≤ 10^17), each of which is a test case input.

The first integer in each line, x, is the base. The second integer in each line, n, is the exponent.

Required to calculate - x to the power n (x^n).

Output Format

The result x^n for each test case on a new line, therefore t lines of output.

Since the value of x^n can be very large print the answer % 1000000007

Sample Input

3

3 1

2 4

5 2

Sample Output

3

16

25

Explanation

Test case 1: 3^1 = 3

Test case 2: 2^4 = 16

Test case 3: 5^2 = 25

My Solution
**************************************************************************************************/


#include <cmath>
#include <cstdio>
#include <map>
#include <iostream>
using namespace std;
map<int, long long> powers;



void calculate(int i, long long a){
// cout<<"calculate "<<a<<" "<<i<<" : ";
	if(i==0){
		powers[i]=1;
	}
	else if(i==1){
		powers[i]=a;
	}
	else
		powers[i]=powers[i-1]*a;
// cout<<"powers["<<i<<"]: "<<powers[i]<<endl;
}


long long pow(long long a,long long b){ 
// cout<<"A: "<<a<<"\tB: "<<b<<endl;
	if(powers.find(b)!=powers.end()){
// cout<<"if"<<endl;
		return powers.find(b)->second;
	}
	else{
// cout<<"else"<<endl;
		if(b%2==0){
// cout<<"even"<<endl;
			powers[b]=pow(a,b/2)*pow(a,b/2);
			return powers[b];
		}
		else{
// cout<<"odd"<<endl;
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


