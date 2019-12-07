//only for undirected graph
//returns the summation of all the weights of a spanning tree such that total weight is minimum
//Prim: At each step, choose the cheapest available edge attached to any previously chosen vertex
// which does not violate the goal of creating a spanning tree.
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

long long int prims(vector<vector<pair<int, int> > >& g, int m, int n){
	priority_queue<PII, vector<PII>, greater<PII> > pq;//this is min heap
							//(lowest priority i.e. minimum weight node is at the top), 
							// to implement max heap -> priority_queue<int> pq;
							//priority queue is used because we want to select the
							// minimum weight edge(connecting any of the previous traversed vertices)
	pq.push({0, 1});//choose any starting vertex(here it's 1)
	vector<int> vis(n+1, false);
	int min_cost = 0;
	while(!pq.empty()){
		pair<int, int> temp = pq.top();
		pq.pop();
		int v = temp.second;//node number
		if(vis[v]){
			continue;
		}
		min_cost += temp.first;//add the edge weight as soon as it is selected
		int levelsize = g[v].size();
		for(int i=0; i<levelsize; i++){
			int child = g[v][i].second;
			int edge_wt = g[v][i].first;//edge weight between v and child
			if(!vis[child]){
				pq.push(make_pair(edge_wt, child));
			}
		}
		vis[v] = true;
	}
	//will come out of the loop when all the vertices have been connected, there might be some redundant iterations, when all the vertices have been visited and queue is still not empty
	return min_cost;
}
int main(){
	//undirected graph
	int n,m;//number of nodes and number of edges
	cin>>n>>m;
	vector<vector<PII > >g(n+1);
	for(int i=0;i<m;i++){
		int a, b, wt;//source, destination, weight
		cin>>a>>b>>wt;
		g[a].push_back(make_pair(wt,b));
		g[b].push_back(make_pair(wt,a));
	}
	long long int min_cost = prims(g,m,n);
	cout<<min_cost<<endl;
	return 0;
}