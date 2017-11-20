/*Q4.2) Minimal Tree: Given a sorted (increasing order) array with unique integer 
		elements, write an algorithm to create a binary search tree with minimal height.*/

#include<iostream>
#include<vector>

using namespace std;

struct BSTNode{
	int data;
	BSTNode* left, *right;
	BSTNode(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};

BSTNode* createTreeHelper(vector<int> &a, int l, int r){
	if(l>r) return NULL;
	
	int m=(r+l)/2;
	BSTNode *r1=new BSTNode(a[m]);
	
	r1->left=createTreeHelper(a,l,m-1);
	r1->right=createTreeHelper(a, m+1,r);
	
	return r1;
}

void preorder(BSTNode* n){
	if(n==NULL) return;
	cout<<n->data<<" ";
	preorder(n->left);
	preorder(n->right);		
}

main(){
	vector<int> a;
	for(int i=1;i<7;i++) a.push_back(i);
	BSTNode* r=createTreeHelper(a,0,a.size()-1);
	preorder(r);
	return 0;
}
