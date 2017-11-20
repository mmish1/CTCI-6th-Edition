/*Q2.8) Loop Detection: Given a circular linked list, implement an algorithm that returns the 
		node at the beginning of the loop. DEFINITION Circular linked list: A (corrupt) linked 
		list in which a node's next pointer points to an earlier node, so as to make a loop in 
		the linked list. 
		EXAMPLE Input: A -> B -> C -> D -> E -> C [the same C as earlier] 
				Output: C */


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
	for(int i=0;i<6;i++){
		cout<<head->data<<" -> ";
		head=head->next;
	}
	head==NULL?cout<<"null":cout<<" ";
	cout<<endl;
}

Node* remove(Node* &head, Node* n){
	while(head!=n){
		head=head->next;
		n=n->next;
	}
	return head;
}

Node* detectCycle(Node* head){
	Node* fast=head, *slow=head;
	while(fast && fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow) return remove(head,slow);
	}
	return NULL;
}

void dispResult(Node* n){
	if(n) cout<<"Cycle starts at: "<<n->data<<endl;
	else cout<<"No cycle"<<endl;
}

main(){
	Node * list1 = new Node(3);
	list1->next = new Node(6);
	list1->next->next = new Node(9);
	list1->next->next->next = new Node(12);
	list1->next->next->next->next = new Node(15);
	list1->next->next->next->next->next = list1->next->next;
	cout<<"Linked list 1: ";
	print(list1);
	dispResult(detectCycle(list1));
	
	Node* head=NULL;
	insert(head,4);
	insert(head,8);
	insert(head,6);
	insert(head,9);
	insert(head,6);
	insert(head,5);
	cout<<"\nLinked list 2: ";
	print(head);
	dispResult(detectCycle(head));
	return 0;
}
