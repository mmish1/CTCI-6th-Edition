#include<iostream>
#include<cmath>
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

int length(Node* n){
	int c=0;
	while(n){
		c++;
		n=n->next;
	}
	return c;
}

void reverse(Node* &head){
	if(head==NULL || head->next==NULL) return;
	Node* newHead=NULL, *nextNode=NULL;
	while(head){
		nextNode=head->next;
		head->next=newHead;
		newHead=head;
		head=nextNode;		
	}
	head=newHead;
}

bool palindrome(Node* head){
	Node* slow=head,*fast=head, *cur;
	while(fast && fast->next){
		slow=slow->next;
		fast=fast->next->next;
	}
	
	if(fast && fast->next==NULL){
		slow=slow->next;
	}
	
	reverse(slow);
	fast=head;
	while(slow && fast){
		if(slow->data==fast->data){
			slow=slow->next;
			fast=fast->next;
		}
		else return false;
	}
	return true;
}

void dispResult(bool a){
	if(a) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
}

main(){
	Node* head=NULL;
	insert(head,7);
	insert(head,8);
	insert(head,6);
	insert(head,6);
	insert(head,8);
	insert(head,7);
	cout<<"Original Linked list: ";
	print(head);
	cout<<"Is the linked list a palindrome? ";
	dispResult(palindrome(head));
	return 0;
}
