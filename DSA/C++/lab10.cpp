#include <iostream>
#include <vector>
#include <queue>


#define WHITE 0
#define GRAY 1
#define BLACK 2

std::vector<int> center;
std::vector<int> mins;
std::vector<int> maxs;
class vertex{
public:
	int color;
	int dist,final;
	int par;
	std::vector<int> next;
	vertex(){
		color=WHITE;
		dist=-1;
		par=-1;
		final=-1;
	}
};


void bfs(std::vector<vertex> &g, int s){
	int verts=g.size(),i=0;
//	std::cout<<"s:"<<s<<"\n";
	mins[s]=-1;
	std::queue<int> que;

	g[s].color=GRAY;
	g[s].dist=0;
	que.push(s);
	//std::cout<<s<<"\t";			
	// std::cout<<"bfs2\n";
	while(que.size()!=0){
		// std::cout<<"wh1\n";
		int curr=que.front();
		que.pop();
		// std::cout<<"gCurrNextSize: "<<g[curr].next.size()<<"\n";
		for(i=0;i<g[curr].next.size();i++){
			// std::cout<<"for\n";
			if(g[g[curr].next[i]].color==WHITE){
				// std::cout<<"if\n";
				g[g[curr].next[i]].color=GRAY;
				g[g[curr].next[i]].dist=g[curr].dist+1;
			//	std::cout<<"MIN["<<s<<"]="<<mins[s]<<"G CUR NEXT DIST :"<<g[g[curr].next[i]].dist<<"\n";
				if(g[g[curr].next[i]].dist > mins[s]){
					mins[s]=g[g[curr].next[i]].dist;
				}
				g[g[curr].next[i]].par=curr;
				que.push(g[curr].next[i]);	
				//std::cout<<g[curr].next[i]<<"\t";
			}
			
		}
		g[curr].color=BLACK;
	}
	

}

int findMin(std::vector< std::vector<int> > &adjMat){
	int i,j,verts=adjMat.size(),min;
	//mins.resize(verts);
	/*
	for(i=0;i<verts;i++){
		maxs[i]=adjMat[i][0];
		for(j=i+1;j<verts;j++){
			if(adjMat[i][j]>maxs[i]){
				maxs[i]=adjMat[i][j];
			}
		}
	}
	*/
	min=verts;
	for(i=0;i<verts-1;i++){
		if(maxs[i]<min){
			min=maxs[i];
		}
	}
	
	return min;
}

int findMax(std::vector< std::vector<int> > &adjMat){
	int i,j,verts=adjMat.size(),max=adjMat[0][0];
	maxs.resize(verts);
	
	for(i=0;i<verts;i++){
		maxs[i]=adjMat[i][0];
		for(j=i+1;j<verts;j++){
			if(adjMat[i][j]>maxs[i]){
				maxs[i]=adjMat[i][j];
			}
		}
	}
	
	max=maxs[0];
	for(i=0;i<verts;i++){
		if(maxs[i]>max){
			max=maxs[i];
		}
	}
	
	return max;
}

void computeCenter(std::vector< std::vector<int> > &adjMat, int min){
	int i,verts=adjMat.size(),j;
	for(i=0;i<verts;i++){
		if(maxs[i]==min){
			center.push_back(i);
		}
	}
}

void printdistMat(std::vector< std::vector<int> > &adjMat){
	int i,j, verts=adjMat.size();
	std::cout<<"distances:: \n";
	for(i=0;i<verts;i++){
		for(j=0;j<verts;j++){
			std::cout<<adjMat[i][j]<<"\t";
		}		
	std::cout<<"\n";
	}
}

void initialize(std::vector<vertex> &G){
	int i,verts=G.size(),j;
	for(i=0;i<verts;i++){
		G[i].color=WHITE;
	}
}

void computeDist(std::vector< std::vector<int> > &adjMat, std::vector<vertex> &G){
	int i,verts=G.size(),j;
	mins.resize(verts);
//	std::cout<<"\n verts: "<<verts<<"\n";
	for(i=0;i<verts;i++){
		initialize(G);
		bfs(G,i);
		for(j=0;j<verts;j++){
			adjMat[i][j]=G[j].dist;
		}
	}

	//printdistMat(adjMat);
	int max=findMax(adjMat);
	int min=findMin(adjMat);

	computeCenter(adjMat,min);	
	
	std::cout<<"\nDiameter: "<<max;
	std::cout<<"\nRadius: "<<min;
	std::cout<<"\nCenter: \n";

	for(i=0;i<center.size();i++){
		std::cout<<"\t"<<center[i]+1;
	}
	std::cout<<"\n";
}

int checkBipartite(std::vector<vertex> &vertices2){
	int i,j,verts=vertices2.size();
	for(i=0;i<verts;i++){
		if(i==0){
			vertices2[i].color=BLACK;
			for(j=0;j<vertices2[i].next.size();j++){
				if(vertices2[vertices2[i].next[j]].color==WHITE){
					vertices2[vertices2[i].next[j]].color=GRAY;
				}
				else if(vertices2[vertices2[i].next[j]].color==BLACK){
					std::cout<<"NOT BIPARTITE because of vertex "<<i+1<<" and "<<vertices2[i].next[j]+1<<"\n";
					return 0;
				}
				else if(vertices2[vertices2[i].next[j]].color==GRAY){
					continue;
				}
				else{
					std::cout<<" ERROR IN COLORING\n";
				}
			}
		}	
		else{
			if(vertices2[i].color==BLACK){
			for(j=0;j<vertices2[i].next.size();j++){
				if(vertices2[vertices2[i].next[j]].color==WHITE){
					vertices2[vertices2[i].next[j]].color=GRAY;
					}
					else if(vertices2[vertices2[i].next[j]].color==BLACK){
						std::cout<<"NOT BIPARTITE because of "<<i+1<<","<<vertices2[i].next[j]+1<<"\n";
						return 0;
					}
					else if(vertices2[vertices2[i].next[j]].color==GRAY){
						continue;
					}
					else{
						std::cout<<" ERROR IN COLORING\n";
					}
				}
			}
			
			else if(vertices2[i].color==GRAY){
				for(j=0;j<vertices2[i].next.size();j++){
					if(vertices2[vertices2[i].next[j]].color==WHITE){
						vertices2[vertices2[i].next[j]].color=BLACK;
					}
					else if(vertices2[vertices2[i].next[j]].color==GRAY){
						
						std::cout<<"NOT BIPARTITE because "<<i+1<<","<<vertices2[i].next[j]+1<<" lie in an odd cycle\n";
						
						return 0;
					}
					else if(vertices2[vertices2[i].next[j]].color==BLACK){
						continue;
					}
					else{
						std::cout<<" ERROR IN COLORING\n";
					}
				}
			}
		}
	}
	
	return 1;
}


int main(){
	int verts,i,j;

	std::cin>>verts;
	std::vector<vertex> vertices(verts,vertex());
	std::vector<vertex> vertices2(verts,vertex());

	std::vector< std::vector<int> > adjMat;
	adjMat.resize(verts);
	std::vector<int> temp(verts,-1);
	for(i=0;i<verts;i++){
		adjMat[i]=temp;
	}
	
	for(i=0;i<verts;i++){
		for(j=0;j<verts;j++){
			int conn;
			std::cin>>conn;
			if(j>i){
				if(conn==1){
					vertices[i].next.push_back(j);
					vertices[j].next.push_back(i);			
					vertices2[i].next.push_back(j);
					vertices2[j].next.push_back(i);			
				}
			}
		}
	}
	int flag=2;
	flag=checkBipartite(vertices2);
	if (flag==1){
		std::cout<<" GRAPH IS BIPARTITE \n";
	}
	computeDist(adjMat,vertices);
	return 1;
}
