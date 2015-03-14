/**************************************************************************************************
Problem Statement

You have a system which can remember at most K words at a time. So, when (K+1)th word arrives, your program forgets the 1st word, when (K+2)th word arrives, your program forgets the 2nd word, and so on. After reading each new word the system needs to report the most frequent word over the last K words read and its frequency. If the system has read less than K words you have to report from the words that have been read till now.

In a nutshell, you need to report the most frequent word over the latest K words each time a new word arrives. The most frequent word is the one which has occured the maximum number of times. If there is a tie for the most frequent word, report the alphabetically smaller word.

Constraints

1 ≤ T ≤ 20

1 ≤ K ≤ N ≤ 10^5

1 ≤ word-length ≤ 8

Input Format

The first line of input will contain an integer T, which denotes the number of test cases. First line of each test case will contain two integers N and K, where N is the total number of words to be read, and K is the number of words that your program can remember. Each of the following N lines will contain a single word composed with only lowercase characters ‘a’ to ‘z’, at most 8 characters long.

Output Format

For each case, first print the case number, then for each of the words, print the most frequent word that appears within the last K words along with the frequency. If there are less than K words, then print the most frequent word among all of them. In case there is a tie, print the alphabetically smaller word. See sample input and output sections for more details.

Sample Input

1
8 3
yolo
lite
who
lite
lite
yolo
who
when
Sample Output

Case 1:
yolo 1
lite 1
lite 1
lite 2
lite 2
lite 2
lite 1
when 1

My Solution
**************************************************************************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
void findMax(unordered_map<string,int> count){
 //unordered_map<string,int>::iterator it;
	int max=-1;
	string maxString;
	for(auto it=count.begin();it!=count.end();it++){
 //cout<<it->first<<"\t";
		if(it->second > max){
			maxString=it->first;
			max=it->second;
		}
		else if (it->second == max){
			maxString=(it->first<maxString)?it->first:maxString;
		}
	}
	cout<<maxString<<" "<<max<<"\n";
}
int main() {
 /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int numCases,i,j,n,k;
	cin>>numCases;
	for(i=0;i<numCases;i++){
		cout<<"Case "<<i+1<<":\n";
		vector<string> arr;
		unordered_map<string,int> count;
		cin>>n;
		cin>>k;
		for(j=0;j<n;j++){
			int position=j%k;
			string newString;
 //cout<<position<<"\t";
			cin>>newString;
			if(position<arr.size()){
 //cout<<"Replacing\t";
				string oldString=arr[position];
				int oldCount=count[oldString];
				if(oldCount==1){
					count.erase(oldString);
				}else{
					count[oldString]=oldCount-1;
				}
				arr[position]=newString;
			}
			else{
 //cout<<"Inserting\t";
				arr.push_back(newString);
			} 
			if(count.find(newString)!=count.end()){
				int newCount=count[newString];
				count[newString]=newCount+1;
			}
			else{
				count[newString]=1;
			}
			findMax(count);
		} 
	}
	return 0;
}


