// we can keep track of vertices currently in recursion stack of function for DFS traversal. 
//If we reach a vertex that is already in the recursion stack, then there is a cycle in the tree.

bool dfs(vector<int> adj[], map<int, int> &m, vector<bool> &vis, int v){
    if(m.find(v) != m.end()){
        return true;
    }
    m[v] = 1;
    vis[v] = true;
    bool res = false;
    for(int i=0; i<adj[v].size(); i++){
        res = dfs(adj, m, vis, adj[v][i]);
        if(res){
            m.erase(v);
            return true;
        }
    }
    m.erase(v);
    return res;
    
}
bool isCyclic(int V, vector<int> adj[]){
    vector<bool> vis(V, false);//for unconnected and connected(not strongly) components
    bool res = false;
    for(int i=0; i<V; i++){
        map<int, int> m;
        if(!vis[i]){
            res = dfs(adj, m, vis, i);
        }
        if(res){
            return true;
        }
    }
    return res;
}