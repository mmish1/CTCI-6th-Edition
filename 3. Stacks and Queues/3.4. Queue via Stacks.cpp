/*Q3.4) Queue via Stacks: Implement a MyQueue class which implements a queue using two stacks. */

#include<iostream>
#include<stack>

using namespace std;

class MyQueue{
	stack<int> s1;
	stack<int> s2;
	
	void transfer(stack<int> &source, stack<int> &destination){
		while(!source.empty()){
			destination.push(source.top());
			source.pop();
		}
	}
	
public:
	MyQueue(){	}
	
	void enQ(int d){
		s1.push(d);
	}
	
	void dQ(){
		if(s1.empty()) {
			return;
		}
		transfer(s1,s2);
		s2.pop();
		transfer(s2,s1);
	}
	
	bool isEmpty(){
		return s1.empty();
	}
	
	int peek(){
		if(s1.empty()) {
			return -1;
		}
		transfer(s1,s2);
		int a=s2.top();
		transfer(s2,s1);
		return a;
	}
};

void disp(bool a){
	if(a) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
}

main(){
	MyQueue *q=new MyQueue();
	cout<<"start-> ";
	cout<<"Is the queue empty? ";
	disp(q->isEmpty());
	q->enQ(2);
	q->enQ(5);
	q->enQ(8);
	cout<<"Number of enqueues: 3"<<endl;
	cout<<"Top after enq: "<<q->peek()<<endl;
	q->dQ();
	cout<<"Top after 1 pop (-1 means queue is empty): "<<q->peek()<<endl;
	q->dQ();
	cout<<"Top after 2 pops (-1 means queue is empty): "<<q->peek()<<endl;
	q->dQ();
	cout<<"Top after 3 pops (-1 means queue is empty): "<<q->peek()<<endl;
	cout<<"end-> ";
	cout<<"Is the queue empty? ";
	disp(q->isEmpty());
	return 0;
}
