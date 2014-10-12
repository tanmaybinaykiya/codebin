#include <iostream>
#include <cstring>

int flag=0;
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
		//std::cout<<"EMPTY";		
	}
	else{
		if(curr->left!=NULL){
			printInorder(curr->left);
		}
		//std::cout<<curr->key<<"\t";		

		if(curr->right!=NULL){
			printInorder(curr->right);
		}
	}
}

void printPreOrder(node *curr){
	if(curr==NULL){
		std::cout<<"EMPTY";
	}
	else{
		std::cout<<curr->key<<" ";			

		if(curr->left!=NULL){
			printPreOrder(curr->left);
		}
		else{
			std::cout<<"leftNull ";		
		}

		if(curr->right!=NULL){
			printPreOrder(curr->right);
		}
		else{
			std::cout<<"rightNull ";		
		}
	}
}

node * rotateLL(node *root, node *c){
	
	node *b=c->left;
	if(c->left==NULL){
	 std::cout<<"b is NULL SHOULD NEVER HAPPEN\n";
	}

	if(c->parent!=NULL){
		if(c->parent->left==c){
			c->parent->left=b;
		}
		else{
			c->parent->right=b;
		}
		b->parent=c->parent;
	}
	else{
		root=b;
		b->parent=NULL;
	}
	
	c->left=b->right;
	if(b->right!=NULL)
		b->right->parent=c;

	b->right=c;
	c->parent=b;
	return root;
}

node * rotateRR(node *root, node *c){

	node *b=c->right;
	
	if(c->parent!=NULL){
		if(c->parent->left==c){
			c->parent->left=b;
		}
		else{
			c->parent->right=b;
		}
		b->parent=c->parent;
	}
	else{
		
		root=b;
		b->parent=NULL;
	}
	
	c->right=b->left;
	if(b->left!=NULL)
		b->left->parent=c;

	b->left=c;
	c->parent=b;

	return root;
}

node * rotateRL(node *root, node *c){

	root=rotateLL(root,c->right);
	root=rotateRR(root,c);
	return root;
}

node * rotateLR(node *root, node *c){
	root=rotateRR(root,c->left);
	root=rotateLL(root,c);
	return root;
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
		// //std::cout<<"curr:"<<curr->key<<"\n";
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

int treeHeight(node *curr){

	int leftHeight=0,rightHeight=0;
	
	if(curr==NULL){
		return 0;
	}

	if(curr->left!=NULL){
		leftHeight=treeHeight(curr->left)+1;
	}
	
	if(curr->right!=NULL){
		rightHeight=treeHeight(curr->right)+1;
	}

	return (leftHeight<rightHeight)? rightHeight:leftHeight;
}

node * findImbalance(node *root, node *curr){
	int i;
	// if(flag==1){
	// 	usleep(1000000);
	// }

	for(i=0;i<5;i++){
		int lHeight=0, rHeight=0;
		
		if(curr->left!=NULL){
			lHeight=treeHeight(curr->left)+1;
		}
		if(curr->right!=NULL){
			rHeight=treeHeight(curr->right)+1;
		}
		

		if(((lHeight-rHeight)<-1)||((lHeight-rHeight)>1)){
			return curr;
		}
		else{


			if(curr->parent!=NULL){
				curr=curr->parent;
			}
			else{
				break;
			}
		}
	}
	return NULL;
}

node * balance(node *root, node *curr){
	node *newCurr=findImbalance(root,curr);

	if(newCurr==NULL){
		return root;
	}
	
	int lHeight=0,rHeight=0;
	if(newCurr->left!=NULL)
		lHeight=treeHeight(newCurr->left);
	
	if(newCurr->right!=NULL)
		rHeight=treeHeight(newCurr->right);

	if(lHeight>rHeight){
		int llHeight=0,lrHeight=0;
		
		if(newCurr->left->left!=NULL)
			llHeight=treeHeight(newCurr->left->left);
		if(newCurr->left->right!=NULL)
			lrHeight=treeHeight(newCurr->left->right);

		if(llHeight>lrHeight){
			rotateLL(root,newCurr);
		}
		else{
			rotateLR(root,newCurr);
		}
	}
	else{
		int rlHeight=0,rrHeight=0;
		
		if(newCurr->right->left!=NULL)
			rlHeight=treeHeight(newCurr->right->left);
	
		if(newCurr->right->right!=NULL)
			rrHeight=treeHeight(newCurr->right->right);

		if(rlHeight>rrHeight){
			root=rotateRL(root,newCurr);
		}
		else{
			root=rotateRR(root,newCurr);
		}
	}
	return root;
}

node * deleteNode(node *root, int key){
	node *del,*delParent=NULL;
	del=findKey(root,key);

	if(del->parent!=NULL){
		delParent=del->parent;
	}


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
		//std::cout<<key<<" NOT FOUND\n";
	}

	if(delParent!=NULL){
		root=balance(root,delParent);
	}
	// else{
	// 	root=balance(root,root);
	// 	if(root->left!=NULL)
	// 		root=balance(root,root->left);
		
	// 	if(root->right!=NULL)
	// 		root=balance(root,root->right);
	// }

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
			//std::cout<<"root Inserted\n";
		}
		else{
			//std::cout<<"Inserting new node...\n";
			temp=new node(key);
			insertNode(root,temp);
			if(key==20){
//				flag=1;
			}
			// //std::cout<<"Preorder: \t : ";
			// printPreOrder(root);
			// //std::cout<<"\n";
			root=balance(root,temp);
			// //std::cout<<"balanced root:"<<root->key<<"\n";
			//std::cout<<"temp : "<<key<<"\n";
			

			//usleep(1000000);
		}
	}
	// //std::cout<<"OUT\n";
	//printInorder(root);
	//std::cout<<"\n";
	std::cout<<"\nPREORDER :\n";
	printPreOrder(root);
	std::cout<<"\n";

	// root=deleteNode(root, 176262);
	// printInorder(root);
	// //std::cout<<"\n";

	// printInorder(root);
	// //std::cout<<"\n";

	return 0;
} 
