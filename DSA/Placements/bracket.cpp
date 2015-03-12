#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
int testString(string input){
	int i=0;
	vector<char> myStack;
	for(;i<input.size();i++){
		char head;
		if(myStack.size()>0)
			head=myStack[myStack.size()-1];
		else
			head='\0';
		char inpChar=input.at(i);
		if(inpChar=='{' || inpChar=='[' || inpChar=='(' || inpChar=='<'){
			myStack.push_back(inpChar);
		}
		else if( inpChar=='}'){
			if( head=='{' ){
				myStack.pop_back();
			}
			else return 0;
		}
		else if( inpChar==']'){
			if( head=='[' ){
				myStack.pop_back();
			}
			else return 0;
		}
		else if( inpChar==')'){
			if( head=='(' ){
				myStack.pop_back();
			}
			else return 0;
		}
		else if( inpChar=='>'){
			if( head=='<' ){
				myStack.pop_back();
			}
			else return 0;
		}
	} 
	if(myStack.size()==0){
		return 1;
	}
	else
		return 0;
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	vector<char> input;
	string temp;
	int testCaseNum=0,i=0;
	cin>>testCaseNum;
	int ctr=0;
	for(i=0;i<testCaseNum;i++){
		cin>>temp;
		if(testString(temp)==1){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
	return 0;
}