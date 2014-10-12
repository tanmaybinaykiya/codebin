#include <iostream>
#include <vector>
#include <queue>

#define WHITE 0
#define GRAY 1
#define BLACK 2

int tim;

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

void bfs(std::vector<vertex> &g,int s){
// std::cout<<"bfs\n";
	int verts=g.size(),i=0;
	std::queue<int> que;

	g[s].color=GRAY;
	g[s].dist=0;
	que.push(s);
	std::cout<<s<<"\t";			
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
				g[g[curr].next[i]].par=curr;
				que.push(g[curr].next[i]);	
				std::cout<<g[curr].next[i]<<"\t";
			}
		}
		g[curr].color=BLACK;
	}
}
void dfsVisit(std::vector<vertex> &g,int v){
	std::cout<<v<<"\t";
	tim++;
	g[v].dist=tim;
	g[v].color=GRAY;
	int i;
	for(i=1;i<g[v].next.size();i++){
		if(g[g[v].next[i]].color==WHITE ){
			g[g[v].next[i]].par=v;
			dfsVisit(g,g[v].next[i]);
		}
	}
	g[v].color=BLACK;
	tim++;
	g[v].final=tim;
}

void dfs(std::vector<vertex> &g){
	int size=g.size(),i;
	for(i=1;i<size;i++){
		g[i].color=WHITE;	
		g[i].dist=-1;
	}
	tim=0;
	for(i=1;i<size;i++){
		if(g[i].color==WHITE){
			dfsVisit(g,i);
		}
	}
}

int main(){
	int verts=5,i=0,edges=5;
	std::cin>>verts;
	std::vector<vertex> vertices(verts+1,vertex());
	std::cin>>edges;

	// std::cout<<"verts"<<verts<<" edges"<<edges<<"\n";

	for(i=0;i<edges;i++){
		int v1=0,v2=0;
		std::cin>>v1;
		std::cin>>v2;
		// std::cout<<"v1:"<<v1<<" v2:"<<v2<<"\n";
		vertices[v1].next.push_back(v2);
		vertices[v2].next.push_back(v1);
		// std::cout<<"I:"<<i<<"\n";
	}

	bfs(vertices,1);
	std::cout<<"\n";
	dfs(vertices);

	return 1;
}