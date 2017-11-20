/*Q4.4) Check Balanced: Implement a function to check if a binary tree is balanced. 
		For the purposes of this question, a balanced tree is defined to be a tree 
		such that the heights of the two subtrees of any node never differ by more than one. */

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

int height(BSTNode *root){
	if(root==NULL) return 0;
	return max(height(root->left),height(root->right))+1;
}

bool isBalanced(BSTNode *root){
	if(root==NULL) return true;
	int rh,lh;
	rh=lh=0;
	lh=height(root->left);
	rh=height(root->right);
	if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right)) return true;
	return false;
}

main(){
	BSTNode *root=new BSTNode(10);
	root->left=new BSTNode(2);
	root->right=new BSTNode(8);
	root->left->left=new BSTNode(6);
	root->left->right=new BSTNode(12);
	root->left->left->left=new BSTNode(25);
	
	if(isBalanced(root)) cout<<"yes";
	else cout<<"no";
}
