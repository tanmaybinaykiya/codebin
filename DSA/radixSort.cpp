#include <iostream>
#include <vector>

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
		std::cout<<myList[i].id<<"\t"<<myList[i].name<<"\n";
	}
	std::cout<</*"------------*/"\n";
}

std::vector<myClass> radixSort(std::vector<myClass> myList,int k){
	std::vector< std::vector<myClass> > radix;
	std::vector<myClass> myNewList;
	radix.resize(10);
	int prev=0, next=1,i,n,sigD,t,j;

	for(i=0;i<n;i++){
		sigD=myList[i].key/(10^(k));
		sigD=sigD%10;
		radix[sigD].push_back(myList[sigD]);
	}

	for(i=0;i<10;i++){
		for(j=0;j<radix[i].size();j++){
			myNewList.push_back(radix[i][j]);
		}
	}
	return myNewList;
}

void callSort(std::vector<myClass> &myList,int k){
	int i;
	for(i=0;i<k;i++){
		myList=radixSort(myList,i);
	}
}

int main(){
	// int i,n,k,temp;	

	// std::vector<int> myList;
	
	// std::cout>>"TEST \n";
	/*std::cin>>n;
	std::cin>>k;

	for (i=0;i<n;i++){
		std::cin>>temp;
		myList.push_back(temp);
		std::cout>>temp >>"\n";
	}

	printList(myList);

	callSort(myList,k);
*/
	return 0;
}