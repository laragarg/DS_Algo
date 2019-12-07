//Number of cycles of length n in an undirected graph
#include<bits/stdc++.h>
using namespace std;
vector<bool> vis;
int ans;
void dfs(int n, int start, int v, int cycle_size){
    vis[v] = true;//for this dfs
    if(cycle_size == n-1){
        for(int i=0; i<g[v].size(); i++){
            if(g[v][i] == start){
                ans++;
                break;
            }
        }
        vis[v] = false;
        return;
    }
    int sz = g[v].size();
    for(int i=0; i<sz; i++){
        int child = g[v][i];
        if(!vis[child]){
            dfs(n, start, child, cycle_size+1);
        }
    }
    vis[v] = false;//for further traversals
}
int main(){
    ans = 0;
    vector<vector<int> >g;//normal adjacency list
    vis.clear();
    vis.resize(V+1, false);
    // 1. We need to find all the paths of length n-1 and if we can complete the cycle
    // by adding one more edge then increase the counter.
    // 2. Optimization -> applying dfs on V-(n-1) edges would be sufficient.
    for(int i=1; i<=(V - (n-1)); i++){
        if(!vis[i]){
            dfs(int n, i, i, 0);
        }
        vis[i] = true;
    }
    cout<<ans<<endl;
    return 0;
}