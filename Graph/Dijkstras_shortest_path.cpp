//At each step, choose the edge attached to any previously chosen vertex which 
//makes the total distance from the starting vertev as small as possible, 
//and does not violate the goal of creating a spanning tree.
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
void dijkstra(vector<vector<pair<int, int> > >& g, vector<int> &dis, int m, int n){   
    priority_queue<PII, vector<PII>, greater<PII> > pq;
    pq.push({0,1});
    vector<int> vis(n+1, false);
    dis[1]=0;
    while(!pq.empty()){
        PII temp=pq.top();
        pq.pop();
        int v = temp.second;//node number
        if(vis[v]){
            continue;
        }
        int neighbours = g[v].size();
        for(int i=0; i<neighbours; i++){
            int child = g[v][i].second;
            int edge_wt = g[v][i].first;//edge weight between v and child 
            if(dis[v]+edge_wt < dis[child] && !vis[child]){ //Core logic
                dis[child]=dis[v]+edge_wt;
                pq.push({dis[child], child});
            }
        }
        vis[v]=true;
    }
    return;
}
int main(){
    //directed graph(but it can be implemented for undirected as well)
    int n,m;//number of nodes and number of edges
    cin>>n>>m;
    vector <vector <pair <int,int> > > g(n+1);
    for(int i=0;i<m;i++){
        int a, b, wt;//source, destination, weight
        cin>>a>>b>>wt;
        g[a].push_back(make_pair(wt,b));
        }
    vector<int> dis(n+1, 1e9);//initalize distance(from source to all the nodes) as infinity
    dijkstra(g, dis, m, n);
    for(int i=2;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    return 0;
}