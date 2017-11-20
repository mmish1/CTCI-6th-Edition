/*Q2.1) Move Dups: Write code to remove duplicates from an unsorted linked list. 
		FOLLOW UP How would you solve this problem if a temporary buffer is not allowed? */


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

/*Inplace solution*/
void noDups(Node* &head){
	Node* cur=head, *prev;
	while(cur && cur->next!=NULL){
		prev=cur;
		while(prev && prev->next!=NULL){
			if(cur->data==prev->next->data) prev->next=prev->next->next;
			prev=prev->next;
		}
		cur=cur->next;
	}
}

main(){
	Node* head=NULL;
	insert(head,7);
	insert(head,8);
	insert(head,6);
	insert(head,9);
	insert(head,6);
	insert(head,7);
	insert(head,7);
	cout<<"Original Linked List: ";
	print(head);
	noDups(head);
	cout<<"Linked List after removing duplicates: ";
	print(head);
	
}
