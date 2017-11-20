/*Q4.8) First Common Ancestor: Design an algorithm and write code to find the first 
		common ancestor of two nodes in a binary tree. Avoid storing additional nodes 
		in a data structure. NOTE: This is not necessarily a binary search tree. */

#include<iostream>

using namespace std;

struct BSTNode{
	int val;
	BSTNode *left, *right;
	BSTNode(int d){
		val=d;
		left=NULL;
		right=NULL;
	}
};

BSTNode* ancestor(BSTNode* root, int a, int b){
	if(root==NULL) return NULL;
	
	if(root->val==a || root->val==b) return root;
	
	BSTNode* l=ancestor(root->left, a, b);
	BSTNode* r=ancestor(root->right, a, b);
	
	if(l&&r) return root;
	
	return l!=NULL?l:r;
}

main(){
	BSTNode *root=new BSTNode(1);
	root->left=new BSTNode(2);
	root->right=new BSTNode(3);
	root->left->left=new BSTNode(4);
	root->left->right=new BSTNode(5);
	root->right->left = new BSTNode(6);
	root->right->right = new BSTNode(7);
	
	cout << "LCA(4, 5) = " << ancestor(root, 4, 5)->val;
    cout << "\nLCA(4, 6) = " << ancestor(root, 4, 6)->val;
    cout << "\nLCA(3, 4) = " << ancestor(root, 3, 4)->val;
    cout << "\nLCA(2, 4) = " << ancestor(root, 2, 4)->val;
	
	return 0;
}
