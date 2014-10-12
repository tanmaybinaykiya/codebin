#include <iostream>
#include <vector>

class myClass{
	public:
		int id;
		std::string name;
		myClass(){
		}
		myClass(int a, std::string b){
			id=a;
			name=b;
		}
		~myClass(){};		
};

void printList(std::vector<myClass> &myList){
	int i=1,size=myList.size();
	for(i=1;i<size;i++){
		std::cout<<myList[i].id<<"\t"<<myList[i].name<<"\n";
	}
	//std::cout<<myList[i].id<<"\t"<<myList[i].name<<"\n";
}

void printTree(std::vector<myClass> &myList){
	int i=0,size=0;
	size=myList.size();
	for(i=1;i<=size/2;i++){
		std::cout<<"Parent: "<<myList[i].id;
		if(size>(2*i))
			std::cout<< "\tChild1: "<<myList[2*i].id<< "";
		else
			std::cout<< "\tChild1 :NULL";

		if(size>(2*i+1))
			std::cout<< "\tChild2: "<<myList[2*i+1].id<< "\n";
		else
			std::cout<< "\tChild2 :NULL\n";
	}
}

void maxHeapify(std::vector<myClass> &myList,int i){
	int size=myList.size();
	myClass temp;
	if(i!=0){
	// std::cout<<"MAX HEAPIFY\n";
		while(i<size){
			// std::cout<<"i= "<<i<<":\t"<<myList[i].id<<"\t2i:"<<myList[2*i].id<<"\t2i+1:"<<myList[2*i+1].id<<"\n";
			if(myList[i].id<myList[2*i].id){
				temp=myList[i];
				myList[i]=myList[2*i];
				myList[2*i]=temp;
				maxHeapify(myList,i);
				i*=2;

			}
			else if(myList[i].id<myList[1+(2*i)].id){
				temp=myList[i];
				myList[i]=myList[1+(2*i)];
				myList[1+(2*i)]=temp;
				maxHeapify(myList,i);
				i*=2;
				i++;
			}
			else{
				break;
			}
		}
	}	
}	
/*
void maxHeapify(std::vector<myClass> &myList,int i){
	int size=myList.size();
	myClass temp;
	std::cout<<"MAX HEAPIFY\n";
	while(i>1){
		std::cout<<"i= "<<i<<":\t"<<myList[i].id<<"\tparent:"<<myList[i/2].id<<"\n";
		if(myList[i].id>myList[i/2].id){
			temp=myList[i];
			myList[i]=myList[i/2];
			myList[i/2]=temp;
			maxHeapify(myList,i);
			i/=2;
		}
		else{
			break;
		}
	}
}
*/

myClass extractMax(std::vector<myClass> &myList){
	int size=myList.size()-1;
	myClass max=myList[1];
	myList[1]=myList[size];

	myList.erase(myList.end()-1);
	maxHeapify(myList,1);

	return max;
}


void heapify(std::vector<myClass> &myList){
	int size=myList.size(),i=0;
	for(i=size-1;i>0;i--){
		maxHeapify(myList,i);
	}
}

void heapSort(std::vector<myClass> &myList){
	std::vector<myClass> temp=myList;
	int i,size=myList.size();
	for(i=size-1;i>1;i--){
		temp[size-1-i]=extractMax(myList);
	}
	myList=temp;
}

int main(){
	std::vector<myClass> myList,myList2;
	std::string sName;
	int sId=0,i=0,n=0,toFind=-1;
	
	std::cin>>n;
	myList.push_back(myClass(-1,"DUMMY"));
	for(i=0;i<n;i++){
		std::cin>>sId;
		std::cin>>sName;
		myList.push_back(myClass(sId,sName));
		// std::cout<<sId<<"\t";
	}
	// std::cout<<"\n";
	// printList(myList);
	// printTree(myList);
	heapify(myList);
	std::cout<<"HEAPIFIED\n";
	// printList(myList);
	heapSort(myList);
	std::cout<<"HEAP SORTED\n";
	printList(myList);
	// printTree(myList);
	return 0;
}