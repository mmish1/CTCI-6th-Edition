/*Q2.3) 2.3 Delete Middle Node: Implement an algorithm to delete a node in the middle 
			(i.e., any node but the first and last node, not necessarily the exact middle) 
			of a singly linked list, given only access to that node. 
			EXAMPLE Input:the node c from the linked lista->b->c->d->e->f 
					Result: nothing is returned, but the new linked list looks like a->b->d->e->f */

#include<iostream>

using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int d): data{d}, next{NULL} {}
};

/*Insert at the front*/
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


void deleteMiddleNode(Node* &n){
	if(n->next==NULL) n=NULL;
	else{
		n->data=n->next->data;
		n->next=n->next->next;
	}
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
	deleteMiddleNode(head->next->next);
	cout<<"Linked list after deleting 6: ";
	print(head);
	deleteMiddleNode(head);
	cout<<"Linked list after deleting 7: ";
	print(head);
	deleteMiddleNode(head->next->next->next->next);
	cout<<"Linked list after deleting 4: ";
	print(head);
	return 0;
}
