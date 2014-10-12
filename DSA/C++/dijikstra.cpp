#include <iostream>
#include <vector>

std::vector< std::vector<int> > dijkstra(std::vector< std::vector<int> > &G, int w, int s){
	std::vector< std::vector<int> > distVector;
	int size=G.size();
	distVector.resize(size);

	for(i=0;i<size;i++){
		std::vector<int> temp(size,-1);
		distVector[i]=temp;
	}

}

void printAdj(std::vector< std::vector<int> > &adjList){
	std::cout<<"Adjacency List:\n";	

	int i,j,size=adjList.size();
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			std::cout<<adjList[i][j]<<"\t";
		}	
		std::cout<<"\n";
	}	
}

int main(){
	int verts=5,i=0,edges=5;
	std::cin>>verts;
	std::vector< std::vector<int> > adjList;
	adjList.resize(verts);

	for(i=0;i<verts;i++){
		std::vector<int> temp(verts,-1);
		adjList[i]=temp;
	}

	std::cin>>edges;

	for(i=0;i<edges;i++){
		int v1=0,v2=0,weight=-1;
		std::cin>>v1;
		std::cin>>v2;
		std::cin>>weight;
		// std::cout<<"\t v1:"<<v1<<"\t v2:"<<v2<<"\t w:"<<weight<<"\n";
		adjList[v1-1][v2-1]=weight;
		adjList[v2-1][v1-1]=weight;
		// std::cout<<"v1 V2 "<<adjList[v1-1][v2-1]<<"\t";	
		// std::cout<<"v2 V1 "<<adjList[v2-1][v1-1]<<"\n";	
	}
	std::cout<<"Input Complete\n";	

	printAdj(adjList);



}
