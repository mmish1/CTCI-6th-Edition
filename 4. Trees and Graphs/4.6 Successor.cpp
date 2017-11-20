/*Q4.6) Successor: Write an algorithm to find the "next" node (i.e., in-order successor) of a 
		given node in a binary search tree. You may assume that each node has a link to its parent*/

#include<iostream>
#include<cmath>
using namespace std;

/*solution without parent link*/
struct BSTNode{
	int val;
	BSTNode *left, *right;
	BSTNode(int d){
		val=d;
		left=NULL;
		right=NULL;
	}
};

BSTNode* findmin(BSTNode* root){
	while(root->left){
		root=root->left;
	}
	return root;
}

/*Recursive Method*/
BSTNode* successor(BSTNode* root, int key, BSTNode *prev){
	if(root->val!=key){
		if(root->val>key) {
			prev=root;
		}
		if(key<=root->val) {
			return successor(root->left,key,prev);
		}
		else return successor(root->right,key,prev);
	}
	
	if(root->right!=NULL) return findmin(root->right);
	if(prev->val<root->val) prev=NULL;
	
	return prev;
}

/*Iterative Method*/
BSTNode* successor(BSTNode* root, int key){
	BSTNode* prev=root, *cur=root;
	while(cur->val!=key){
		if(cur->val>key) prev=cur;
		if(key<=cur->val) cur=cur->left;
		else cur=cur->right;
	}
	
	if(cur->right!=NULL) return findmin(cur->right);
	if(prev->val<cur->val) prev=NULL;
	
	return prev;
}

main(){
	BSTNode *root=new BSTNode(20);
	root->left=new BSTNode(8);
	root->right=new BSTNode(22);
	root->right->left=new BSTNode(21);
	root->right->right=new BSTNode(25);
	root->left->left=new BSTNode(4);
	root->left->left->right=new BSTNode(6);
	root->left->left->right->left=new BSTNode(5);
	root->left->right=new BSTNode(12);
	root->left->right->left=new BSTNode(10);
	root->left->right->right=new BSTNode(14);
	
	cout<<"iterative function: \n";
	cout<<successor(root,20)->val<<endl<<endl;
	cout<<successor(root,14)->val<<endl<<endl;
	if(successor(root,25)==NULL)	cout<<"NULL"<<endl<<endl;
	cout<<successor(root,21)->val<<endl<<endl;
	cout<<successor(root,4)->val<<endl<<endl;
	cout<<successor(root,6)->val<<endl<<endl;
	cout<<successor(root,5)->val<<endl<<endl;

	cout<<"recursive function: \n";
	cout<<successor(root,20,root)->val<<endl<<endl;
	cout<<successor(root,14,root)->val<<endl<<endl;
	if(successor(root,25,root)==NULL)	cout<<"NULL"<<endl<<endl;
	cout<<successor(root,21,root)->val<<endl<<endl;
	cout<<successor(root,4,root)->val<<endl<<endl;
	cout<<successor(root,6,root)->val<<endl<<endl;
	cout<<successor(root,5,root)->val<<endl<<endl;
	
	return 0;
}
