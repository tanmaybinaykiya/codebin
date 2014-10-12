#include <iostream>
#include <vector>
int bucketCount=10;

class myClass{
	public:
		int key;
		std::string name;
		myClass(){
		}
		myClass(int a, std::string b){
			key=a;
			name=b;
		}
		myClass(int a){
			key=a;
			name='x';
		}
		~myClass(){};		
};

void printList(std::vector<myClass> &myList){
	std::cout<<"LIST: \n";
	int i=0;
	for(i=0;i<myList.size();++i){
		std::cout<<myList[i].key<<"\t"/*<<myList[i].name<<"\n"*/;
	}
	std::cout<</*"------------*/"\n";
}


int findPosition(std::vector<myClass> &myList,int left,int right,int keyIndex){ //using Binary Search
	if(right-left<=1){	//Base Case
		if(myList[left].key>myList[keyIndex].key){
			return (left-1);
		}
		else if(myList[right].key>myList[keyIndex].key){
			return left;
		}
		else{
			return right;
		}
	}
	else{
		int mid=(left+right)/2;
		if((myList[mid].key<myList[keyIndex].key)&&(myList[mid+1].key>=myList[keyIndex].key)){
			return mid;
		}
		else if(myList[mid].key>myList[keyIndex].key){
			findPosition(myList,left,mid,keyIndex);
		}
		else{
			findPosition(myList,mid,right,keyIndex);
		}
	}
}

void insertAt(std::vector<myClass> &myList,int pos,int keyIndex){
		myClass temp=myList[keyIndex];

		for(int i=keyIndex;i>pos+1;--i){
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

void bucketSort(std::vector<myClass> &myList,int max,int min){
	// std::cout<<"BS max:"<<max<<" min: "<<min<<"\n";
	int size=myList.size();
	int step=(max-min),i,j,k;
	step/=bucketCount;
	std::vector< std::vector<myClass> > buckets;

	buckets.resize(bucketCount);
	for (i = 0; i < size; i++){
		buckets[myList[i].key/step].push_back(myList[i]);
	}
	i=0;
	
	while(i<bucketCount){
		insertionSort(buckets[i]);
		i++;
	}	

	k=0;
	for (i = 0; i < bucketCount; i++){
		for(j=0;j<buckets[i].size();j++){
			myList[k]=buckets[i][j];
			k++;
		}
	}	
}

int main(){

	std::vector<myClass> myList;
	std::string sName;
	int sId=0,i=0,n=0,max=0,min=0;

	std::cin>>n;
	for(i=0;i<n;++i){
		std::cin>>sId;
		myList.push_back(myClass(sId));
		max = (max>sId) ? max : sId;
		min = (min<sId) ? min : sId;
	}
	printList(myList);
	bucketSort(myList,(int)(max*1.1),min);
	printList(myList);
	return 1;
}