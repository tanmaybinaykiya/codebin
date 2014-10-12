#include <iostream>
#include <list>
#include <vector>
#include <string>

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

void printList(std::list<myClass> &myList){
	std::list<myClass>::iterator it;
	std::cout<<"\n";
	for(it=myList.begin();it!=myList.end();++it){
		
		std::cout<<it->id<<"\t"/*<<it->name<<std::endl*/;
	
	}
	std::cout<<"\n------------------------------------------------\n";	
}

void printList(std::list<myClass> &myList,std::list<myClass>::iterator left,std::list<myClass>::iterator right){
	std::list<myClass>::iterator it;

	//if (right==myList.end()){printList(myList);}
	/*else*/{
		for(it=left;it!=right;++it){
			std::cout<<it->id<<"\t"/*<<it->name<<std::endl*/;
		}
	}
	std::cout<<"\n";
}

void bubbleSortById(std::list<myClass> &myList){
	std::list<myClass>::iterator it1,it2,it3;

	for(it1=myList.end();it1!=myList.begin();it1--){
		for(it2=myList.begin();it2!=it1;it2++){
			it3=++it2;
			if(it3==myList.end())
				break;
			it2--;
			if( ((it2) -> id) > ((it3)->id)){
				if(it2==it1){
					it1--;
				}	
 				myList.insert(it2,myClass((it3)->id,(it3)->name));
				myList.erase(it3);
				it2--;
			}
		}
	}
}

std::list<myClass>::iterator mergeSort(std::list<myClass> &myList,std::list<myClass>::iterator left, std::list<myClass>::iterator right){
	std::cout<<"L:"<<left->id<<",R:"<<right->id<<"\n";
	if(left!=right){
		std::list<myClass>::iterator mid,l,r;
		int dist;
		dist=distance(left,right);
		std::cout<<"D:"<<dist<<"\n";
		mid=left;
		advance(mid,dist/2);

		left=mergeSort(myList,left,mid++);
		mid=mergeSort(myList,mid,right);


		right++;
		l=left;
		r=mid;
		while(l->id!=mid->id){
			std::cout<<"Comparing L:"<<l->id<<",mid:"<<mid->id<<",R:"<<r->id<<",Right:"<<right->id<<"\n";
			
			if(l->id >= r->id ){
				l=myList.insert(l,myClass(r->id,r->name));
				if(r==right){
					r=myList.erase(r);
					std::cout<<"Swapped, Breaking \n";
					break;
				}
				else{	
					r=myList.erase(r);
					std::cout<<"Swapped \n";
				}
				if(l->id==mid->id) break;
			}
			else{
				std::cout<<"LI8 \n";
				l++;
				if(l->id==mid->id) break;
			}
			
		}
		//printList(myList,left,right);
		right--;
	}
	//printList(myList,left,right);
	return left;
}

std::list<myClass>::iterator binarySearch(std::list<myClass> &myL,std::list<myClass>::iterator left, std::list<myClass>::iterator right, int key){

	int mid;
	std::list<myClass>::iterator it;
	it=left;
	//std::cout<<"left ID:"<<left->id<<"\t right ID:"<<right->id;
	right--;
	if(left!=right){
		right++;
		mid=distance(left,right)/2;
		advance(it,mid);
		//std::cout<<"\t IT ID:"<<it->id<<"\n";
		if(it->id==key){
			return it;
		}
		else if(it->id>key){
			return (binarySearch(myL,left,it--,key));
		}
		else if(it->id<key){
			return (binarySearch(myL,it++,right,key));
		}
	}
	else{
		return myL.end();
	}	
}


int mainOLD(){
	std::list<int> myList;
	std::list<int>::iterator it;
	int n=0,i=0,var=0;
	std::cin>>n;

	for(i=0;i<n;i++){
		std::cin>>var;
		myList.push_back(var);
	}

	it=myList.begin();

	for(it=myList.begin();it!=myList.end();++it){
		std::cout<<*it<<std::endl;
	}

	return 1;
}
/*
int mainOLD2(){
	std::list<myClass> myList;
	std::list<myClass>::iterator it;
	std::string sName;
	int sId=0,i=0,n=0,toFind=-1;

	std::cin>>n;

	for(i=0;i<n;i++){
		std::cin>>sId;
		std::cin>>sName;
		myList.push_back(myClass(sId,sName));
	}
	std::cin>>toFind;

	//bubbleSortById(myList);
	printList(myList);
	it=mergeSort(myList,myList.begin(),myList.end());
	printList(myList);
	

	//it=binarySearch(myList, myList.begin(),myList.end(),toFind);

	//if(it!=myList.end())
	//	std::cout<<"Name of "<<toFind<<" is :"<<it->name<<"\n";
	//else
	//	std::cout<<"Not Found \n";
	
	return 1;
}
*/
void printList(std::vector<myClass> &myList){
	std::cout<<"LIST: \n";
	int i=0;
	for(i=0;i<myList.size();i++){
		std::cout<<myList[i].id<<"\t"<<myList[i].name<<"\n";
	}
	std::cout<<"------------\n";
}

std::vector<myClass> createVector(std::vector<myClass> &myList, int left, int right){
	int i;
	std::vector<myClass> newV;
	for(i=left;i<right;i++){
		newV.push_back(myList[i]);
	}
	return newV;
}
/*
std::vector<myClass> mergeSort(std::vector<myClass> &myList){

	if(myList.size()>1){
		std::cout<<"MergeSort of";
		int mid=myList.size()/2, l=0,r=0,i;
		
		printList(myList);

		std::vector<myClass> left,right;

		left=createVector(myList, 0, mid);
		right=createVector(myList, mid+1, myList.size());

		left=mergeSort(left);
		right=mergeSort(right);

		for(i=0;l<myList.size();i++){
			if(left[l].id <= right[r].id){
				myList[i]=left[l];
				l++;
				if(l==left.size()){
					while(r!=right.size()){
						myList[i]=right[r];
					}
					break;
				}	
			}
			else{
				myList[i]=right[r];
				r++;
				if(r==right.size()){
					while(l!=left.size()){
						myList[i]=left[l];
					}
					break;
				}	
			}
		}
		
	}
	return myList;
}
*/

int mainOLD3(){
	std::vector<myClass> myList;

	std::string sName;
	int sId=0,i=0,n=0,toFind=-1;

	std::cin>>n;

	for(i=0;i<n;i++){
		std::cin>>sId;
		std::cin>>sName;
		myList.push_back(myClass(sId,sName));
	}

	printList(myList);
	myList=mergeSort(myList);
	printList(myList);

}

