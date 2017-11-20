/*Q4.1) Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a route between two nodes. */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{
	int val;
	vector<int> *adj;
	public:
		Graph(int x){
			val=6;
			adj=new vector<int> [x];
		}
		
		void addEdge(int s, int d){
			adj[s].push_back(d);
		}
		
		bool isRoute(int s, int d){
			queue<int> q;
			q.push(s);
			while(!q.empty()){
				int temp=q.front();
				if(temp==d) return true;
				
				q.pop();
				for(int i=0;i<adj[temp].size();i++){         
					q.push(adj[temp][i]);
				}
				
			}
			return false;
		}
};

void translate(bool x){
	if(x) cout<<"yes"<<endl;
	else cout<<"no\n";
}

main(){
	Graph *g=new Graph(6);
	g->addEdge(5,0);
	g->addEdge(5,2);
	g->addEdge(2,3);
	g->addEdge(4,0);
	g->addEdge(4,1);
	g->addEdge(3,1);
	
	cout<<"route from 5 to 4: ";
	translate(g->isRoute(5,4));
	cout<<"route from 5 to 1: ";
	translate(g->isRoute(5,1));
}
