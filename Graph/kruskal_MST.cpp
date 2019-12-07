//only for undirected graph
//returns the summation of all the weights of a spanning tree such that total weight is minimum
//Edge traversal(like in bellman ford)
#include<bits/stdc++.h>
using namespace std;
typedef pair<long long int, long long int> PII;
int root(int x, vector<int> &id){
    while(id[x] != x){
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}
void union1(int x, int y, vector<int> &id){
    int root_x = root(x, id);
    int root_y = root(y, id);
    id[root_x] = id[root_y];//or id[root_x] = root_y
}

long long kruskal(vector< pair<long long int, PII > > &g, vector<int> &id){
    int x, y;
    long long cost, min_cost = 0;
    for(int i=0; i<g.size(); i++){
        x = g[i].second.first;
        y = g[i].second.second;
        cost = g[i].first;
        if(root(x, id) != root(y, id)){//if nodes doesn't add a cycle to MST
            min_cost += cost;
            union1(x, y, id);
        }
    }
    return min_cost;
    
}
int main(){
    int n, m;
    cin>>n>>m;//nodes and edges
    vector<int> id(n+1);//initialization
    for(int i=1; i<=n; i++){
        id[i] = i;
    }
    vector< pair<long long int, PII > > g(m);//{weight, {a, b}}
    for(int i=0; i<m ;i++){
        int a, b, c;
        cin>>a>>b>>c;
        g[i] = make_pair(c , make_pair(a, b) );
    }
    sort(g.begin(), g.end());//don't forget to sort
    int ans = kruskal(g, id);
    cout<<ans<<endl;
    return 0;
}