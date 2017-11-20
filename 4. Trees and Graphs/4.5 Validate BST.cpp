/*Q4.5) Validate BST: Implement a function to check if a binary tree is a binary search tree. */

#include<iostream>
#include<cmath>
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

bool findMax(BSTNode* root){	
	if(root->left == NULL ||		
	   (root->left->val <= root->val && 
	   (root->left->right == NULL || (root->left->right!= NULL && root->left->right->val <= root->val)))
	) return true;
	return false;
}

bool findMin(BSTNode* root){
	if(root->right == NULL ||		
	   (root->right->val > root->val && 
	   (root->right->left == NULL || (root->right->left!= NULL && root->right->left->val > root->val)))
	) return true;
	return false;
}

bool isValid(BSTNode* root){
	if(root==NULL) return true;
	return (findMax(root)) && (findMin(root));
}

main(){
	BSTNode *root=new BSTNode(3);
	root->left=new BSTNode(2);
	root->right=new BSTNode(5);
	root->left->left=new BSTNode(1);
	root->left->right=new BSTNode(4);
	root->right->right=new BSTNode(25);
	
	if(isValid(root)) cout<<"yes";
	else cout<<"no";
	
	return 0;
}
