/*Q2.7) Intersection: Given two (singly) linked lists, determine if the two lists intersect. 
		Return the intersecting node. Note that the intersection is defined based on reference, 
		not value. That is, if the kth node of the first linked list is the exact same node 
		(by reference) as the jth node of the second linked list, then they are intersecting. */


#include<iostream>
#include<cmath>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int d): data{d}, next{NULL} {}
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

int length(Node* n){
	int c=0;
	while(n){
		c++;
		n=n->next;
	}
	return c;
}

bool intersect(Node* n1,Node* n2){
	int len1=length(n1);
	int len2=length(n2);
	Node* l,*s;
	l=len1>len2?n1:n2;
	s=len1>len2?n2:n1;
	int x=abs(len1-len2);
	while(x){
		l=l->next;
		x--;
	}
	while(l && s){
		if(l==s) return true;
		l=l->next;
		s=s->next;
	}
	return false;
}

void dispResult(bool a){
	if(a) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
}

main(){
	Node * list1 = new Node(3);
	list1->next = new Node(6);
	list1->next->next = new Node(9);
	list1->next->next->next = new Node(12);
	list1->next->next->next->next = new Node(15);
	list1->next->next->next->next->next = new Node(18);
	
	Node * list2 = new Node(7);
	list2->next = new Node(10);
	list2->next->next = list1->next->next->next;

	cout<<"List 1: ";
	print(list1);
	cout<<"List 2: ";
	print(list2);
	cout<<"Intersection? ";
	dispResult(intersect(list1,list2));
	return 0;
}
