#include <iostream>
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
		// std::cout<<"EMPTY";		
	}
	else{
		if(curr->left!=NULL){
			printInorder(curr->left);
		}
		// std::cout<<curr->key<<"\t";		

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
		std::cout<<" "<<curr->key;			
	
		if(curr->left!=NULL){
			printPreOrder(curr->left);
		}
		else{
			std::cout<<" lNULL";	
		}

		if(curr->right!=NULL){
			printPreOrder(curr->right);
		}
		else{
			std::cout<<" rNULL";		
		}
	}
}

node * rotateLL(node *root, node *c){
	// std::cout<<"ROTATE LL\n";
	
	node *b=c->left;
	// std::cout<<"ROTATE LL2\n";

	if(b==NULL){
		// std::cout<<"b is NULL\n";
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
	// std::cout<<"ROTATE LL3\n";
	
	c->left=b->right;
	// std::cout<<"ROTATE LL3.5\n";
	if(b->right!=NULL)
		b->right->parent=c;
	// std::cout<<"ROTATE LL4\n";

	b->right=c;
	c->parent=b;
	// std::cout<<"ROTATE LL5\n";
	
	// std::cout<<"PREORDER :\t";
	// printPreOrder(root);
	return root;
}

node * rotateRR(node *root, node *c){
	// std::cout<<"RR\n";
	node *b=c->right;

	if(b==NULL){
		// std::cout<<"b is NULL\n";
		return 0;
	}	
	// std::cout<<"C: "<<c->key<<"\n";
	// std::cout<<"B: "<<b->key<<"\n";
	
	if(c->parent!=NULL){
		// std::cout<<"if1\n";
		if(c->parent->left==c){
			// std::cout<<"if2\n";
			c->parent->left=b;
		}
		else{
			// std::cout<<"ife\n";
			c->parent->right=b;
		}
		// std::cout<<"if11\n";
		b->parent=c->parent;
		// std::cout<<"if12\n";

	}
	else{
		root=b;
		b->parent=NULL;
		// std::cout<<"Root is"<<root->key<<"\n";
	}
	// std::cout<<"RR2\n";

	c->right=b->left;
	if(b->left!=NULL)
		b->left->parent=c;

	// std::cout<<"RR3\n";
	b->left=c;
	c->parent=b;
	// std::cout<<"RR4\n";

	// std::cout<<"PREORDER :\t";
	// printPreOrder(root);

	return root;
}

node * rotateRL(node *root, node *c){
	// std::cout<<"ROTATE RL\n";
	// std::cout<<"c->right:"<<c->right->key<<"\n";

	root=rotateLL(root,c->right);
	// std::cout<<"ROTATE lL done\n";
	root=rotateRR(root,c);
	// std::cout<<"ROTATE RR done\n";
	return root;
}

node * rotateLR(node *root, node *c){
	// std::cout<<"LR\n";
	root=rotateRR(root,c->left);
	// std::cout<<"LR2\n";
	root=rotateLL(root,c);
	// std::cout<<"LR3\n";
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

int treeHeight(node *curr){

	// std::cout<<"\ntreeHeight\n----------------\n";
	// std::cout<<"curr: "<<curr->key<<"\t";
	int leftHeight=0,rightHeight=0;
	
	if(curr==NULL){
		// std::cout<<"curr=NULL\n";
		return 0;
	}

	if(curr->left!=NULL){
		// std::cout<<"treeHeight2\n";
		leftHeight=treeHeight(curr->left)+1;
		// std::cout<<"lHeight incremented \n";
	}
	
	if(curr->right!=NULL){
		// std::cout<<"cr!NULL\n";
		rightHeight=treeHeight(curr->right)+1;
		// std::cout<<"rHeight incremented \n";
	}

	// std::cout<<"TH6\n";
	// std::cout<<"curr: "<<curr->key<<"\t";
	// std::cout<<"l: "<<leftHeight<<"\t";
	// std::cout<<"r: "<<rightHeight<<"\n";
	return (leftHeight<rightHeight)? rightHeight:leftHeight;
}

node * findImbalance(node *root, node *curr){
	int i;
	// std::cout<<"\nfindImbalance\n";
	for(i=0;i<5;i++){
		int lHeight=0, rHeight=0;
		
		if(curr->left!=NULL){
			lHeight=treeHeight(curr->left)+1;
		}
		if(curr->right!=NULL){
			rHeight=treeHeight(curr->right)+1;
		}
		
		if(flag==1){
			// std::cout<<"curr: "<<curr->key<<"\t";
			// std::cout<<"l: "<<lHeight<<"\t";
			// std::cout<<"r: "<<rHeight<<"\n";
		}

		if(((lHeight-rHeight)<-1)||((lHeight-rHeight)>1)){
			if(flag==1){
				// std::cout<<"IFcurr: "<<curr->key<<"\t";
				// std::cout<<"l: "<<lHeight<<"\t";
				// std::cout<<"r: "<<rHeight<<"\n";
			}
			return curr;
		}
		else{

			if(flag==1){
				// std::cout<<"ELSE\tcurr: "<<curr->key<<"\t";
				// std::cout<<"curr->parent: "<<curr->parent->key<<"\t";
			
			}

			if(curr->parent!=NULL){
				curr=curr->parent;
			}
			else
				break;
		}
	}
	// std::cout<<"IMbalance3\n";
	return NULL;
}

node * balance(node *root, node *curr){
	// std::cout<<"\nbalance: "<<curr->key << "\n";
	node *newCurr=findImbalance(root,curr);
	// std::cout<<"--------------------\nafter finding Imbalance\n";

	if(newCurr==NULL){
		// std::cout<<"\nNo Imbalance\n";
		return root;
	}
	// std::cout<<"IT IS Imbalanced at : "<<newCurr->key<<"\n";
	
	int lHeight=0,rHeight=0;
	if(newCurr->left!=NULL)
		lHeight=treeHeight(newCurr->left);
	
	if(newCurr->right!=NULL)
		rHeight=treeHeight(newCurr->right);
	// std::cout<<"If there exists imbalance\n";

	if(lHeight>rHeight){
		// std::cout<<"lh>rH\n";
		int llHeight=-1,lrHeight=-1;
		
		if(newCurr->left->left!=NULL){
			llHeight=treeHeight(newCurr->left->left);
		}
		if(newCurr->left->right!=NULL){
			lrHeight=treeHeight(newCurr->left->right);
		}

		if(llHeight>lrHeight){
			// std::cout<<"ll\n";
			rotateLL(root,newCurr);
		}
		else if(llHeight<lrHeight){
			// std::cout<<"lr\n";
			rotateLR(root,newCurr);
		}
		else{
			// std::cout<<"LL = LR SOME ERROR \a \n";
		}
	}
	else{
		// std::cout<<"rh>lH\n";
		int rlHeight=-1,rrHeight=-1;
		// std::cout<<"newCurr: "<<newCurr->key<<"\n";
		// std::cout<<"newCurR: "<<newCurr->right->key<<"\n";
		// std::cout<<"newCurRL: "<<newCurr->right->left->key<<"\n";
		
		if(newCurr->right->left!=NULL){
			rlHeight=treeHeight(newCurr->right->left);
		}	
	
		if(newCurr->right->right!=NULL){
			rrHeight=treeHeight(newCurr->right->right);
		}

		// std::cout<<"rlHeight: "<<rlHeight<<"\n";
		// std::cout<<"rrHeight: "<<rrHeight<<"\n";

		if(rlHeight>rrHeight){
			// std::cout<<"ROTRL\n";
			root=rotateRL(root,newCurr);

		}
		else if(rlHeight<rrHeight){
			// std::cout<<"ROTRR\n";
			root=rotateRR(root,newCurr);
		}
		else{
			// std::cout<<"RL = RR SOME ERROR \a \n";
		}
		// std::cout<<"ttt\n";
		
	}
	// std::cout<<"\nPREORDER :\n";
	// printPreOrder(root);
	// std::cout<<"\n";
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
		std::cout<<key<<" NOT FOUND\n";
		return root;
	}

	if(delParent==NULL){
		root=balance(root,root);
		if(root->left!=NULL)
			root=balance(root,root->left);
		
		if(root->right!=NULL)
			root=balance(root,root->right);
	}

	while(delParent!=NULL){
		root=balance(root,delParent);
		delParent=delParent->parent;
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
			// std::cout<<"root Inserted\n";
		}
		else{
			// std::cout<<"Inserting new node...\n";
			temp=new node(key);
			insertNode(root,temp);
			// std::cout<<"\nPreorder: \t : ";
			// printPreOrder(root);
			// std::cout<<"\n";
			// if(key==16800)
			// 	flag=1;
			root=balance(root,temp);
			// std::cout<<"balanced root:"<<root->key<<"\n";
		}
	}
	// std::cout<<"OUT\n";
	// printInorder(root);
	// std::cout<<"\n";
	std::cout<<"\nPREORDER :\n";
	printPreOrder(root);
	std::cout<<"\n";

	root=deleteNode(root, 107770);
	std::cout<<"\nPREORDER :\n";
	printPreOrder(root);
	std::cout<<"\n";

	root=deleteNode(root, 84744);
	std::cout<<"\nPREORDER :\n";
	printPreOrder(root);
	std::cout<<"\n";

	root=deleteNode(root, 176262);
	std::cout<<"\nPREORDER :\n";
	printPreOrder(root);
	std::cout<<"\n";

	return 0;
} 