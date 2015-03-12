#include <iostream>

class node{
public:
	int key;
	node *left,*right,*parent;
	node(){
		key=-1;
		left=NULL;
		right=NULL;		
		parent=NULL;

	}
	node(int k){
		key=k;
		left=NULL;
		right=NULL;		
		parent=NULL;
	}
	~node(){}
};

void printInorder(node *curr){
	if(curr==NULL){
		std::cout<<"EMPTY";		
	}
	else{
		if(curr->left!=NULL){
			printInorder(curr->left);
		}
		std::cout<<curr->key<<"\t";		

		if(curr->right!=NULL){
			printInorder(curr->right);
		}
	}
}
void insertNode(node *root, node *temp){
	node *curr;
	curr=root;
	while(true){
		if( temp->key <=curr->key ){
			if(curr->left!=NULL){
				curr=curr->left;
			}
			else{
				curr->left=temp;
				temp->parent=curr;
				break;
			}
		}
		else{
			if(curr->right!=NULL){
				curr=curr->right;
			}
			else{
				curr->right=temp;
				temp->parent=curr;
				break;
			}
		}
	}
}

node * findKey(node *root, int key){
	node *curr;
	curr=root;

	while(true){
		// std::cout<<"curr:"<<curr->key<<"\n";
		if( curr->key == key ){
			return curr;
		}
		else if( curr->key > key ){
			if(curr->left==NULL){
				return NULL;
			}
			else{
				curr=curr->left;
			}
		}
		else{
			if(curr->right==NULL){
				return NULL;
			}
			else{
				curr=curr->right;
			}
		}
	}
}

node * treeMin(node *curr){
	while(curr->left!=NULL)
		curr=curr->left;

	return curr;
}

node * treeMax(node *curr){
	while(curr->right!=NULL)
		curr=curr->right;

	return curr;
}

node * successor(node *curr){
	if(curr->right!=NULL){
		return treeMin(curr->right);
	}
	node *par;
	par=curr->parent;

	while(par!=NULL && curr==par->right){
		curr=par;
		par=par->parent;
	}
	return par;
}

node * transplant(node *root,node *u,node *v){
	if(u->parent==NULL){
		root=v;
	}
	else if(u==u->parent->left){
		u->parent->left=v;
	}
	else{
		u->parent->right=v;
	}

	if(v!=NULL){
		v->parent=u->parent;
	}
	return root;
}

node * deleteNode(node *root, int key){
	node *del;
	del=findKey(root,key);

	if(del!=NULL){
		if(del->left==NULL){
			root=transplant(root,del,del->right);
		}
		else if(del->right==NULL){
			root=transplant(root,del,del->left);
		}
		else{
			node *tMin;
			tMin=treeMin(del->right);
			if(tMin->parent!=del){
				root=transplant(root,tMin,tMin->right);
				tMin->right=del->right;
				tMin->right->parent=tMin;
			}
			root=transplant(root,del,tMin);
			tMin->left=del->left;
			tMin->left->parent=tMin;
		}
	}	
	else{
		std::cout<<key<<" NOT FOUND\n";
	}
	return root;
}

int main (){
	int i,n,key=0;
	node *root,*temp;

	std::cin>>n;
	for(i=0;i<n;i++){
		std::cin>>key;
		if(i==0){
			root=new node(key);
		}
		else{
			temp=new node(key);
			insertNode(root,temp);
		}
	}
	// std::cout<<"test\n";
	printInorder(root);
	std::cout<<"\n";

	root=deleteNode(root, 453846);
	printInorder(root);
	std::cout<<"\n";

	return 0;
}