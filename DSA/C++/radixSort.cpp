#include <iostream>
#include <vector>
#include <cmath> 

class myClass{
public:
	int key;
	myClass(){

	}
	myClass(int a){
		key=a;
	}
	~myClass(){

	}
};


void printList(std::vector<myClass> &myList){
	std::cout<<"LIST: \n";
	int i=0;
	for(i=0;i<myList.size();i++){
		std::cout<<myList[i].key/*<<"\t"<<myList[i].name*/<<"\n";
	}
	std::cout<</*"------------*/"\n";
}

void printRadix(std::vector< std::vector<myClass> > radix){
	int i,j;

	for(i=0;i<10;i++){
		if(radix[i].size()==0){
			std::cout<<"EMPTY";
		}
		for(j=0;j<radix[i].size();j++){
			std::cout<<radix[i][j].key<<"\t";
		}
		std::cout<<"\n";
	}

}

std::vector<myClass> radixSort(std::vector<myClass> myList,int k){

	std::vector< std::vector<myClass> > radix;
	std::vector<myClass> myNewList;
	radix.resize(10);
	int prev=0, next=1,i,n,sigD,t,j;
	n=myList.size();
	//INTO THE  RADIX
	for(i=0;i<n;i++){
		sigD=myList[i].key/pow(10,k);
		sigD=sigD%10;
		radix[sigD].push_back(myList[i]);
	}
	//INTO THE LIST

	for(i=0;i<10;i++){
		for(j=0;j<radix[i].size();j++){
			myNewList.push_back(radix[i][j]);
		}
	}
	return myNewList;
}

void callSort(std::vector<myClass> &myList,int k){
	int i=0;
	for(i=0;i<k;i++){
		myList=radixSort(myList,i);
	}

}

int main(){
	int i,n,k,temp;	

	std::vector<myClass> myList;
	
	std::cin>>n;
	std::cin>>k;

	for (i=0;i<n;i++){
		std::cin>>temp;
		myList.push_back(temp);
	}

	printList(myList);
	callSort(myList,k);
	printList(myList);
	return 0;
}