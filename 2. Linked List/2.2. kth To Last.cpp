/*Q2.2) Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list. */

#include<iostream>

using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int d){
		data=d;
		next=NULL;
	}
};

void insert(Node* &head, int d){
	Node* newNode=new Node(d);
	if(head==NULL){
		head=newNode;
		return;
	}
	newNode->next=head;
	head=newNode;
}

void print(Node* head){
	Node* cur=head;
	while(cur!=NULL){
		cout<<cur->data<<" -> ";
		cur=cur->next;
	}
	cout<<"null"<<endl;
}

Node* kthToLast(Node* head, int k){
	Node* p1=head,*p2=head;
	while(p1 && k){
		p1=p1->next;
		k--;
	}
	if(p1==NULL && k>0) return p1;
	while(p1){
		p2=p2->next;
		p1=p1->next;
	}
	return p2;
}

void dispResult(Node* n){
	if(n) cout<<n->data<<endl;
	else cout<<"K greater than the length of the list"<<endl;
}

main(){
	Node* head=NULL;
	insert(head,4);
	insert(head,8);
	insert(head,6);
	insert(head,9);
	insert(head,6);
	insert(head,5);
	insert(head,7);
	cout<<"Original Linked list: ";
	print(head);
	cout<<"k=6th Node from the end is: ";
	dispResult(kthToLast(head,6));
	cout<<"k=7th Node from the end is: ";	
	dispResult(kthToLast(head,7));
	cout<<"k=8th Node from the end is: ";	
	dispResult(kthToLast(head,8));
	
	return 0;	
}
