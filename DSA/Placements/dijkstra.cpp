#include <iostream>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <set>
using namespace std;
class myVertex{
public:    
	string name;
	int dist;
	int parent;
	myVertex(string nameV){name=nameV;}
};

vector<myVertex> vertices;
unordered_map< string, int > id;
unordered_map< int, string > name;
vector< vector<int> > adjList;

bool compareVertices(int i, int j){return vertices[i].dist<vertices[j].dist;}

void dijkstra(int primary){
	vector<int> minPrQ;
	for(int i=0;i<vertices.size();i++){
		if(i!=primary){
			vertices[i].parent=INT_MAX;
			vertices[i].dist=INT_MAX;
		}
		minPrQ.push_back(i);
	}
	minPrQ[primary]=0;
	make_heap(minPrQ.begin(),minPrQ.end(),compareVertices);

	while(minPrQ.size()!=0){
		int curr=minPrQ.front();
		pop_heap(minPrQ.begin(),minPrQ.end(),compareVertices);
		minPrQ.pop_back();
		for(int i=0;i<adjList[curr].size();i++){
			int alternatePathWeight=vertices[adjList[curr][i]].dist + 1;
			if(alternatePathWeight<vertices[adjList[curr][i]].dist){
				vertices[adjList[curr][i]].dist=alternatePathWeight;
				vertices[adjList[curr][i]].parent=curr;
			}
		}
	}
}

int main(){
	int numEdges,tests;
	string primary;
	cin>>numEdges;
	cin>>tests;
	for(int i=0;i<numEdges;i++){
		string left,right;
		cin>>left;
		cin>>right;
		if(id.find(left)==id.end()){
			id[left]=id.size()-1;
			name[id[left]]=left;
			myVertex v(left);
			vertices.push_back(v);
			vector<int> temp;
			adjList.push_back(temp);
			assert(vertices[id[left]].name==left);
		}
		if(id.find(right)==id.end()){
			id[right]=id.size()-1;
			name[id[right]]=right;
			myVertex v(right);
			vertices.push_back(v);
			vector<int> temp;
			adjList.push_back(temp);
			assert(vertices[id[right]].name==right);
		}

		adjList[id[left]].push_back(id[right]);
		adjList[id[right]].push_back(id[left]);
	}
	for(int i=0;i<adjList.size();i++){
		cout<<name[i]<<":";
		for(int j=0;j<adjList[i].size();j++){
			cout<<name[adjList[i][j]]<<" ";
		}
		cout<<"\n";
	}
	

	cin>>primary;
	dijkstra(id[primary]);
	for(int i=0;i<tests;i++){
		string query;
		cin>>query;
		cout<<vertices[id[query]].dist<<"\n";
	}
	return 0;
}