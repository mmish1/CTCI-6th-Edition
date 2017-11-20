/*Q4.10) Check Subtree: Tl and T2 are two very large binary trees, with Tl much bigger than T2. Create 
		 an algorithm to determine if T2 is a subtree of Tl. A tree T2 is a subtree of Tl if there 
		 exists a node n in Tl such that the subtree of n is identical to T2. That is, if you cut 
		 off the tree at node n, the two trees would be identical.*/

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

bool isSubTreeHelper(BSTNode* root, BSTNode* subTree){
	if(root==NULL && subTree==NULL) return true;
	if(!root || !subTree) return false;
	if(root->val!=subTree->val) return false;
	return isSubTreeHelper(root->left,subTree->left) && isSubTreeHelper(root->right,subTree->right);
}

bool isSubTree(BSTNode* root, BSTNode* subTree){
	if(!root || !subTree) return false;
	if(root->val==subTree->val) {
		bool r=isSubTreeHelper(root,subTree);
		if(r) return r;
	}
	return isSubTree(root->left, subTree) || isSubTree(root->right,subTree);
}

main(){
	BSTNode* root= new BSTNode(3);
	root->left=new BSTNode(4);
	root->right=new BSTNode(5);
	//root->left->left=new BSTNode(1);
	root->left->right=new BSTNode(2);
	root->left->right->left=new BSTNode(6);
	
	BSTNode* subTree=new BSTNode(4);
	subTree->left=new BSTNode(1);
	subTree->right=new BSTNode(2);
	
	if(isSubTree(root,subTree)) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
		
	return 0;
}
