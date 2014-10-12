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

void insertDirectAddress(vector< vector<myClass> > &T,myClass obj){
	T[(obj.id%10)].push_back(obj);
}

int searchDirectAddress(vector< vector<myClass> > &T,int  key){
	int i=0,slot=key%10,n=T[slot].size();

	for(;i<n;++i){
		if(T[slot][i].id==key){
			return i;
		}
	}
	return -1;
}
void deleteDirectAddress(vector< vector<myClass> > &T,int  key){
	int ind=searchDirectAddress(T,key);
	if(ind==-1){
		cout<<"NOT DELETED\n";
	}
	else{
		T[key%10].erase(T.begin()+ind);
	}
}

int main(){
	vector< vector<myClass> > T;
	T.resize(10);

	int i,n;
	cin>>n;

	for(i=0;i<n;++i){
		myClass obj;
		cin>>obj.id;
		insertDirectAddress(T,obj);
	}

	int ind=searchDirectAddress(T,5);
	if(ind==-1){
		cout<<"NOT FOUND\n";
	}
	else{
		cout<<"FOUND\n";
	}

	return 0;
}
