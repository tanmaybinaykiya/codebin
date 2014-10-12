#include <iostream>
#include <vector>

class node{
	public:
		int key,pId,lId,rId;
		node(){}
		node(int k){
			key=k;
			pId=-1;
			lId=-1;
			rId=-1;		
		}

		node(int k, int p, int l,int r){
			key=k;
			pId=p;
			lId=l;
			rId=r;
		}
};

void printList(std::vector<node> &myList){
	std::cout<<"LIST: \n";
	int i=0;
	for(i=0;i<myList.size();++i){
		std::cout<<myList[i].key<<"\t"/*<<myList[i].name<<"\n"*/;
	}
	std::cout<</*"------------*/"\n";
}

void printInorder(std::vector<node> &myList, int it){
	// std::cout<<"myList["<<it<<"] ="<<myList[it].key<<"\n";
	if(myList[it].lId!=-1){
		printInorder(myList,myList[it].lId);
	}
	std::cout<<myList[it].key<<"\t";		

	if(myList[it].rId!=-1){
		printInorder(myList,myList[it].rId);
	}
}

void insertNode(int index, std::vector<node> &BST){
	if(BST.size()>1){
	int it=0;
	// std::cout<<"key: "<<BST[index].key<<"\n";
		while(it<BST.size()){
			if(BST[index].key<=BST[it].key){
				if(BST[it].lId!=-1){
					it=BST[it].lId;
				}
				else{	//position found
					BST[it].lId=index;
					BST[index].pId=it;
					break;
				}
			}
			else{
				if(BST[it].rId!=-1){
					it=BST[it].rId;
				}
				else{	//position found
					BST[it].rId=index;
					BST[index].pId=it;
					break;
				}
			}
		}	
	}
}

int findElementIndexbyValue(int val, std::vector<node> &BST){
	int index=0, size=BST.size();

	while( (index<size) && (index!=1)){
		if(val==BST[index].key){
			return index;
		}	
		else if (val<BST[index].key){
			index=BST[index].lId;
			// if (index==-1)
			// 	break;
		}
		else {
			index=BST[index].rId;
			// if (index==-1)
			// 	break;
		}
	}

	if(index==-1 || BST[index].key!=val  ){
		index=-1;
	}
	return index;
}

int treeMin(std::vector<node> &BST, int index ){
	while(BST[index].lId!=-1){
		index=BST[index].lId;
	}
	return index;
}


void transplant(std::vector<node> &BST, int u, int v ){
	if(BST[u].pId==-1){					//if u is root
		BST[0]=v;
	}
	else if(u==BST[BST[u].pId].lId){   	// if u is left child
		BST[BST[u].pId].lId=v;
	}
	else {								// if u is right child
		BST[BST[u].pId].rId=v;
	}

	if(v!=-1){
		BST[v].pId=BST[u].pId;
	}

}

int deleteNode(int flag, int val, std::vector<node> &BST ){

	/**
	 	flag = 0   => val is index
	 	flag = 1   => val is key

	 	left  = 0
	 	right = 1

 	**/
	int index=-1,y=-1;
	// std::cout<<"val:"<<val<<"\t";
	
	if(flag==1){
		index=findElementIndexbyValue(val, BST);
		if (index==-1){
			std::cout<<"NOT FOUND \n";
			return 0;
		}
	}
	else{
		index=val;
	}

	// std::cout<<"INDEX== "<<index<<"\n";

	if(index!=0){
		if(BST[index].lId==-1){
			transplant(BST,index,BST[index].rId);
		}
		else if(BST[index].rId==-1){
			transplant(BST,index,BST[index].lId);
		}
		else{
			int succ=treeMin(BST, BST[index].rId);
			if(BST[succ].pId!=index){
				transplant(BST,succ,BST[succ].rId);
				BST[succ].rId=BST[index].rId;
				BST[BST[succ].rId].pId=succ;
			}
			transplant(BST,index,succ);
			BST[succ].lId=BST[index].lId;
			BST[BST[succ].lId].pId=succ;
		}
	}
	else{
		int succ=treeMin(BST, BST[index].rId);

		BST[BST[succ].pId].lId=BST[succ].rId;
		BST[BST[succ].rId].pId=BST[succ].pId;

		BST[succ].lId=BST[0].lId;

		BST[succ].rId=BST[0].rId;

		BST[0]=BST[succ];

	}
	return 1;
}

int main (){

	int i,n,temp=0;
	std::vector<node> BST;

	std::cin>>n;

	for(i=0;i<n;i++){
		std::cin>>temp;
		BST.push_back(node(temp));
		insertNode(i,BST);
	}

	// printList(BST);
	printInorder(BST, 0);
	std::cout<<"\n";

	deleteNode(1,45,BST);
	printInorder(BST,0);
	std::cout<<"\n";


	deleteNode(1,23,BST);
	printInorder(BST,0);
	std::cout<<"\n";

	deleteNode(1,25,BST);
	printInorder(BST,0);
	std::cout<<"\n";


}