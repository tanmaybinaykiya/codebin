#include <iostream>
#include <vector>
using namespace std;

class myClass{
	public:
		int id;
		myClass(){}
		myClass(int i){id=i;}
		~myClass(){}
};

int hash(vector<myClass> &T,int k){
	int size=T.size();
	return (k%size);
}
int hash2( vector<myClass> &T,int k,int i){
	int m=T.size(),c1=1,c2=2;
	// return ((hash(T,k)+i)%m);		//Linear Probing
	return (hash(T,k)+i*c1+i*c2*c2)%m; //quadratic Probing
}

int insertOpenAdd(vector<myClass>  &T,myClass obj){
	int i=0,n=T.size();

	for(i=0;i<n;i++){
		int slot=hash2(T,obj.id,i);
		if(T[slot].id==-1 || T[slot].id==-2 ){
			T[slot]=obj;
			return 1;
		}
	}
	cout<<"ERROR WHILE INSERTING";
	return 0;
}

int searchOpenAdd(vector<myClass>  &T,int key){
	int i=0,n=T.size();
	for(i=0;i<n;i++){
		int slot=hash2(T,key,i);
		if(T[slot].id==key){
			return slot;
		}
		else if(T[slot].id==-1){
			break;
		}
		else if(T[slot].id==-2){
			continue;
		}
		else{
			cout<<"ERROR";
		}
	}
	cout<<"NOT FOUND";
	return -1;
}

void deleteOpenAdd(vector<myClass>  &T,int key){
	int ind=searchOpenAdd(T,key);
	if(ind!=-1 && ind!=-2) {
		myClass obj(-2);
		T[ind]=obj;
		cout<<"Deleted "<<key<<"\n";
	}
}

int main(){
	int size=50;
	myClass obj(-1);
	vector<myClass> T(size,obj);

	int i,n;
	cin>>n;

	for(i=0;i<n;++i){
		int temp;
		cin>>temp;
		myClass tObj(temp);		
		insertOpenAdd(T,tObj);
	}
	deleteOpenAdd(T,289861);
	return 0;
}