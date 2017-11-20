/*Q3.5) Sort Stack: Write a program to sort a stack such that the smallest items are on the top. 
		You can use an additional temporary stack, but you may not copy the elements into any 
		other data structure (such as an array). 
		The stack supports the following operations: push, pop, peek, and is Empty. */

#include<iostream>
#include<stack>

using namespace std;

void disp(stack<int> a){
	while(!a.empty()){
		cout<<a.top()<<" ";
		a.pop();
	}
	cout<<endl;
}

void sortStack(stack<int> &s1){
	stack<int> s2;
	s2.push(s1.top());
	s1.pop();
	while(!s1.empty()){
		int a=s1.top();
		s1.pop();
		if(a>=s2.top()) {
			s2.push(a);
		}
		else{
			int c=0;
			while(!s2.empty() && s2.top()>a){
				s1.push(s2.top());
				s2.pop();
				c++;
			}
			s2.push(a);
			while(c){
				s2.push(s1.top());
				s1.pop();
				c--;
			}
		}
		
	}
	while(!s2.empty()){
		s1.push(s2.top());
		s2.pop();
	}
}

void sortRecursiveHelper(stack<int> &s1, stack<int> &s2){
	if(s1.empty()) return;
	if(s2.empty() || s1.top()>=s2.top()){
		s2.push(s1.top());
		s1.pop();
	}
	else{
		int a=s1.top();
		s1.pop();
		int c=0;
		while(!s2.empty() && s2.top()>a){
			s1.push(s2.top());
			s2.pop();
			c++;
		}
		s2.push(a);
		while(c){
			s2.push(s1.top());
			s1.pop();
			c--;
		}
	}
	sortRecursiveHelper(s1,s2);
}

void sortRecursive(stack<int> &s1){
	stack<int> s2;
	sortRecursiveHelper(s1,s2);
	while(!s2.empty()){
		s1.push(s2.top());
		s2.pop();
	}
}

main(){
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	cout<<"The stack is: ";
	disp(s);
	sortRecursive(s);
	cout<<"The sorted stack is: ";
	disp(s);
	
	return 0;
}
