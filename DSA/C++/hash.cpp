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

int hash(vector< vector<myClass> > &T,int k){
	int size=T.size();
	return k%size;
}

void insertChainedHash(vector< vector<myClass> > &T,myClass obj){
	int slot=hash(T,obj.id);
	T[slot].push_back(obj);
}

int searchChainedHash(vector< vector<myClass> > &T,int  key){
	int i=0,slot=hash(T,key), n=T[slot].size();

	for(;i<n;++i){
		if(T[slot][i].id==key){
			return i;
		}
	}
	return -1;
}
void deleteChainedHash(vector< vector<myClass> > &T,int  key){
	int ind=searchChainedHash(T,key),slot=hash(T,key);
	if(ind==-1){
		cout<<"NOT DELETED\n";
	}
	else{
		T[slot].erase(T[slot].begin()+ind);
	}
}

int main(){
	vector< vector<myClass> > T;
	int size=50;
	T.resize(size);

	int i,n;
	cin>>n;

	for(i=0;i<n;++i){
		myClass obj;
		cin>>obj.id;
		insertChainedHash(T,obj);
	}

	int ind=searchChainedHash(T,5);
	if(ind==-1){
		cout<<"NOT FOUND\n";
	}
	else{
		cout<<"FOUND\n";
	}

	return 0;
}
