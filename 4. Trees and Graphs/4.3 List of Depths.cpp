/*Q4.3) List of Depths: Given a binary tree, design an algorithm which creates a 	
		linked list of all the nodes at each depth 
		(e.g., if you have a tree with depth D, you'll have D linked lists). */

/*Approach: At each level, the nodes are stored as linked lists. The start of each 
			level is stored in a main linked list.
			mainLL0 -> List of level 0 nodes
			   |
			  \/
			mainLL1 -> list of level 1 nodes
			   |
			  \/
			mainLL2 -> list of level 2 nodes
			 .
			 .
			 .
			   |
			  \/
			NULL*/

#include<iostream>
#include<queue>

using namespace std;

struct BSTNode{
	int data;
	BSTNode* left, *right;
	BSTNode(int x){
		data=x;
		left=NULL;
		right=NULL;
	}
};

struct LinkedListNode{
	int val;
	LinkedListNode* next;
	LinkedListNode(int x){
		val=x;
		next=NULL;
	}
};

/*To create a linked list of linked lists*/
struct LinkedListNodePtr{
	LinkedListNode *n;
	LinkedListNodePtr* next;
	LinkedListNodePtr(LinkedListNode *l){
		n=l;
		next=NULL;
	}
};

BSTNode* insertTree(BSTNode* root, int x){
	if(root==NULL){
		BSTNode* newNode=new BSTNode(x);
		root=newNode;
		return root;
	}
	if(x<=root->data) root->left=insertTree(root->left,x);
	else root->right=insertTree(root->right,x);
	
	return root;
}

void inorder(BSTNode* root){
	if(!root) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void printLL(LinkedListNodePtr *ptr){
	int c=0;
	while(ptr!=NULL){
		cout<<"Level "<<c++<<": ";
		LinkedListNode *p=ptr->n;
		while(p!=NULL){
			cout<<p->val<<" ";
			p=p->next;
		}
		cout<<endl;
		ptr=ptr->next;
	}
}

LinkedListNodePtr* listDepths(BSTNode* root){
	queue<BSTNode*> q;
	q.push(root);
	LinkedListNodePtr *llptr=NULL;
	LinkedListNodePtr *llptrhead=NULL;   
	int level = 0;    
	while(!q.empty()) {		
		BSTNode *temp=NULL;
		int c=q.size();    		
		LinkedListNode *cur=NULL;
		LinkedListNode *h=NULL;
		while(c){
			temp=q.front(); 		
			q.pop();
			
			if(h==NULL){
								
				h=new LinkedListNode(temp->data);
				cur=h;
				LinkedListNodePtr *x=new LinkedListNodePtr(h);
				if(llptrhead==NULL) {
					llptr=x;
					llptrhead=llptr;
				}
				else{
					llptr->next=x;
					llptr=x;
				}
			}
			else{
				cur->next=new LinkedListNode(temp->data);
				cur=cur->next;
			}
			
			
			if(temp->left) {
				q.push(temp->left);			
			}
			if(temp->right) {
				q.push(temp->right);				
			}			
			c--;
		}		
		cout << endl;
		level += 1;
	}
	return llptrhead;
}

main(){
	BSTNode *root=NULL;
	root=insertTree(root,10);
	root=insertTree(root,11);
	root=insertTree(root,7);
	root=insertTree(root,9);
	root=insertTree(root,15);
	root=insertTree(root,8);
	cout<<"Inorder traversal: ";
	inorder(root);
	cout<<"\nList of Depths: ";
	printLL(listDepths(root));
	return 0;
}
