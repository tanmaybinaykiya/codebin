#include<iostream>
#include<vector>
#include<vector>
class customer{
public:
	std::string name;
	int arr,dep,pr;
	
	customer(){}
	customer(int i){  //forDummy
		this->name='Z';
		this->pr=-1;	
	};
	customer(std::string Iname, int Iarr, int Idept, int Ipr){
		name=Iname;
		arr=Iarr;
		dep=Idept;
		pr=Ipr;		
	};
	~customer(){}
};

void printHeap(std::vector<customer> &que){
	int size=que.size(),i=1;
	
	for(i=1;i<size;i++){
		std::cout<<que[i].name<<" "<<que[i].pr<<"\t";
	}
	std::cout<<" \n";
}

void minHeapify(std::vector<customer> &que,int i){
	int size=que.size();
	customer temp;
	while(i<size/2){
		if( que[i].pr > que[2*i].pr ){
			temp=que[i];
			que[i]=que[2*i ];
			que[2*i ]=temp;
		}
		else if(que[i].pr>que[2*i +1 ].pr){
			temp=que[i];
			que[i]=que[2*i +1 ];
			que[2*i +1 ]=temp;
		}
		else{
			break;	
		}
	}
}

void heapify(std::vector<customer> &que){
	int i=0,size=que.size();
	for (i=1;i<size/2;i++){
		minHeapify(que,i);
	}
}

void extractMin(std::vector<customer> &que,int t){
	int i=1,size=que.size();
	customer temp;
	if(que.size()==1){
		std::cout<<(t*15)<<"NONE\n";
	}
	else{
		
		std::cout<<(t*15)<<" "<<que[1].name<<"\n";
		que[1]=que[size-1];
		que.pop_back();
	}
}

void increasePriority(std::vector<customer> &que,int i,int key){
	que[i]=key;
	minHeapify(que,i);
}
void remov(std::vector<customer> &que, std::string name){
	int i=1,size=que.size();
//	std::cout<<(t*15)<<" "<<que[1].name<<"\n";
	for(i=1;i<size;i++){
		if(! que[i].name.compare(name) ){
			//std::cout<<" REMOVING "<<que[i].name<<"\n";
			que.erase(que.begin()+i);
			
			break;
		}
	}	
}

void increasePriority(  std::vector<customer> que,std::string name,int pr){
	int i=1,size=que.size();
	for(i=1;i<size;i++){
		if(!que[i].name.compare(name)){
			que[i].pr=pr;
			break;
		}
	}
	minHeapify(que,i);
}
		
int main(){
	
	std::vector<customer> priorityQueue;
	int events=0,arr=0,dep=0,pr=0,i=0,time=0,prevt=0,t=-1;
	std::string name,act;
	customer min;
	priorityQueue.push_back(-1);//dummy
	name="DUMMY";
	
	std::cin>>events;
	for(i=0;i<events;i++){
		//std::cout<<"read: "<< name<<"\n";	
		if(t!=prevt){
			heapify(priorityQueue);
			//printHeap(priorityQueue);
			if(t!=-1)
			extractMin(priorityQueue,t);
			prevt=t;
		}
		
		std::cin>>time;
		std::cin>>name;
		std::cin>>pr;
		std::cin>>act;
		
		t=time/15;
		if(!act.compare("E")){
			priorityQueue.push_back(customer(name,time,-1,pr));    	
		}
		else if(!act.compare("L")){
			remov(priorityQueue,name);
		}
		else if(!act.compare("IP")){
			increasePriority(priorityQueue,name,pr);
			}
		}
		
		while(priorityQueue.size()>1){
			extractMin(priorityQueue,t);
			t++;
		}

	return 0;
}
