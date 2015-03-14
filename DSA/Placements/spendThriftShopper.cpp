/**************************************************************************************************
Problem Statement

You have the prices of n dresses arranged in a line. You have to select any number of dresses such as to get the max sum of prices. But, You cannot choose adjacent dresses.

Input Format

First line contains an integer n. The next line contains n integers which denote the prices of the n dresses.

Example: 4 3 4 5 10

Constraints: n <= 100000 each of the prices < 10e9

Output Format

One integer which is the max price you could obtain by choosing the set of dresses optimally.

Sample Input

4
3 4 5 10
Sample Output

14

Explanation

select 4 and 10



My Solution
**************************************************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void shop(vector<int> list){
int incl=0,excl=0,inclNew=0,exclNew=0;
for(int i=0;i<list.size();i++){
exclNew=(excl>incl)?excl:incl;
inclNew=excl+list[i];
excl=exclNew;
incl=inclNew;
}
int max=(excl>incl)?excl:incl;
cout<<max;
}

 

int main() {
/* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
int n;
cin>>n;
vector<int> list;
 

for(int i=0;i<n;i++){
int temp;
cin>>temp;
list.push_back(temp);
}
shop(list);
return 0;
}
