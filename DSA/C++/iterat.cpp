#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> myList(10,0);
	vector<int>::iterator it1,it2; 

	for(int i=0;i<10;i++){
		myList[i]=i;
	}

	it1=myList.begin()+2;
	it2=myList.begin()+5;
	std::cout<<"it1:"<<*it1<<"\n";
	std::cout<<"it2:"<<*it2<<"\n";

	myList.erase(it1);

	std::cout<<"it1:"<<*it1<<"\n";
	std::cout<<"it2:"<<*it2<<"\n";

	return 1;
}