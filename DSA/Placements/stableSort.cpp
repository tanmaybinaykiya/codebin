/**************************************************************************************************
Problem Statement

Given a number N, followed by N strings. The task is to sort the strings in a stable fashion by length.

The smaller strings come first, followed by the larger strings.

Constraints

N <= 10000
Input Format

The first line contains N followed by N string one in each line.

Output Format

N lines of output, each having a string per line.

The list should be in the sorted order as asked in the question.

Sample Input

4
danish
mayank
abhishek
cool
Sample Output

cool
danish
mayank
abhishek

My Solution
**************************************************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
bool mySort(string a, string b){
 return a.length()<b.length();
}

int main() {
 /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
 int num,i;
 cin>>num;
 vector<string> arr;
 for(i=0;i<num;i++){
 string temp;
 cin>>temp;
 arr.push_back(temp);
 }
 stable_sort(arr.begin(),arr.end(),mySort);
 for(i=0;i<arr.size();i++){
 cout<<arr[i]<<endl;
 }
 return 0;
}
