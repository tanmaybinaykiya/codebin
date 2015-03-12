#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;
int bfs(vector < vector < int > > adjList, int primary,int sink){
	queue<int> toSee;
	unordered_map < int, int > depth;
	depth[primary]=0;
	toSee.push(primary);
	while(toSee.size()!=0){
		int curr=toSee.front();
		
		int currDepth=depth[curr];
		toSee.pop();
		for(int i=0;i<adjList[curr].size();i++){
			if(depth.find(adjList[curr][i])==depth.end()){
				depth[adjList[curr][i]]=currDepth+1;
				toSee.push(adjList[curr][i]);
				if(adjList[curr][i]==sink){
					return depth[adjList[curr][i]];
				}
			}
		}
	}
	return 0;
}
int main(){
	int n,tests;
	string primary;
	cin>>n;
	cin>>tests;
	vector<int> blank;
	long int nSquare;
	nSquare=n;
	nSquare*=nSquare;
	vector < vector < int > > adjList(nSquare,blank);
	// vector< int> queries;
	unordered_map < string, int > id;
	unordered_map < int, string > name;
	for(int i=0;i<n;i++){
		string left;
		string right;
		cin>>left;
		cin>>right;
		if(id.find(left)==id.end()){
			id[left]=id.size()-1;
			name[id[left]]=left;
			// cout<<left<<":"<<id[left]<<"\n";
		}
		if(id.find(right)==id.end()){
			id[right]=id.size()-1;
			name[id[right]]=right;
			// cout<<right<<":"<<id[right]<<"\n";
		}
		// cout<<"Hello: "<<id[right]<<"\n";
		adjList[id[left]].push_back(id[right]);
		// cout<<"Hello: "<<id[left]<<"\n";
		// cout<<"adj::"<<adjList.size();
		// cout<<"r::"<<adjList[id[right]].size();
		adjList[id[right]].push_back(id[left]);

	}
	cin>>primary;
	for(int i=0;i<tests;i++){
		string query;
		cin>>query;
		cout<<bfs(adjList,id[primary],id[query])<<"\n";
	}
	
	// for(int i=0;i<adjList.size();i++){
	// 	cout<<name[i]<<":";
	// 	for(int j=0;j<adjList[i].size();j++){
	// 		cout<<name[adjList[i][j]]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	
	return 0;
}