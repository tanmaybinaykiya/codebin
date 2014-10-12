#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <ctime>

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

std::vector<myClass> createVector(std::vector<myClass> &myList, int left, int right){
	int i;
	std::vector<myClass> newV;
	for(i=left;i<right;i++){
		newV.push_back(myList[i]);
	}
	return newV;
}

void printList(std::vector<myClass> &myList){
	std::cout<<"\n LIST: \n";
	int i=0;
	for(i=0;i<myList.size();i++){
		std::cout<<myList[i].id<<"\t"<<myList[i].name<<"\n";
	}
	std::cout<</*"------------*/"\n";
}

std::vector<myClass> mergeSort(std::vector<myClass> &myList){
	int len=myList.size();

	if(len==1){
		return myList;
	}
	else{
		int mid=len/2,l=0,r=0,i=0;
		std::vector<myClass> left,right,merged;
		
		left=createVector(myList,0,mid);		//mid not included
		right=createVector(myList,mid,len);		//mid included right not

		left=mergeSort(left);
		right=mergeSort(right);

		for(i=0;i<myList.size();i++){
			if(l!=left.size() && r!=right.size()){
				if(left[l].id<=right[r].id){
					merged.push_back(left[l]);
					l++;
				}
				else{
					merged.push_back(right[r]);
					r++;
				}
			}
			else if(l==left.size()){
					merged.push_back(right[r]);
					r++;
			}	
			else if(r==right.size()){
					merged.push_back(left[l]);
					l++;
			}
			else{
				break;
			}
		}
		return merged;
	}
}

int findPosition(std::vector<myClass> &myList,int left,int right,int keyIndex){ //using Binary Search
	if(right-left<=1){	//Base Case
		if(myList[left].id>myList[keyIndex].id){
			return (left-1);
		}
		else if(myList[right].id>myList[keyIndex].id){
			return left;
		}
		else{
			return right;
		}
	}
	else{
		int mid=(left+right)/2;

		if((myList[mid].id<myList[keyIndex].id)&&(myList[mid+1].id>=myList[keyIndex].id)){
			return mid;
		}
		else if(myList[mid].id>myList[keyIndex].id){
			findPosition(myList,left,mid,keyIndex);
		}
		else{
			findPosition(myList,mid,right,keyIndex);
		}

	}
}

void insertAt(std::vector<myClass> &myList,int pos,int keyIndex){
		myClass temp=myList[keyIndex];

		for(int i=keyIndex;i>pos+1;i--){
			myList[i]=myList[i-1];
		}
		myList[pos+1]=temp;
}

void insertionSort(std::vector<myClass> &myList){
	for(int keyIndex=1;keyIndex<myList.size();keyIndex++){
		int pos=findPosition(myList,0,keyIndex-1,keyIndex);
		insertAt(myList,pos,keyIndex);
	}
}

void printTime(){
	time_t now = time(0);
	char* dt = ctime(&now);
	std::cout << "time is: " << dt << std::endl;
}


int main(){
	std::vector<myClass> myList,myList2;
	std::string sName;
	int sId=0,i=0,n=0,toFind=-1;
	
	std::cin>>n;

	for(i=0;i<n;i++){
		std::cin>>sId;
		std::cin>>sName;
		myList.push_back(myClass(sId,sName));
	}
	//printList(myList);
	std::cout<<"Before \n";
	printTime();
	myList2=mergeSort(myList);
	std::cout<<"After Merge \n";
	printTime();
	insertionSort(myList);
	std::cout<<"After insertionSort \n";
	printTime();
	//printList(myList);
	//printList(myList2);
}