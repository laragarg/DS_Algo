//M1 using disjoint
vector<int> id;
// vector<int> vis;
int root(int x){
    while(id[x] != x){
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}
void union1(int x, int y){
    int root_x = root(x);
    int root_y = root(y);
    id[root_x] = root_y;
}
bool isCyclic(vector<int> adj[], int V){
    id.clear();
    // vis.clear();
    id.resize(V);
    for(int i=0; i<V; i++){
        id[i] = i;
    }
    // for(int )
    map<pair<int, int>, int> vis;
    //for every unvisited edge, check if two nodes belong to 2 different subsets
    for(int i=0; i<V; i++){
        int a = i;
        for(int j=0; j<adj[a].size(); j++){
            int b = adj[a][j];
            if(vis.find({a, b}) == vis.end() && vis.find({b, a}) == vis.end()){
                vis[{a, b}] = 1;
                if(root(a) == root(b)){
                    return true;
                }
                else{
                    union1(a, b);
                }
            }
            // else if(m.find({a, b}) != m.end()){to pass GFG ka chutiya test case
            //     return true;
            // }
        }
    }
    return false;
}

//M2 Using dfs
//for every vis node v, if there is an adjacent node u such that u is already vis
//and u is not parent of v then there is a cycle in the graph

vector<bool> vis;
bool dfs(vector<int> adj[], int u, int p){
	//3 nodes current(u), parent and child, if all are different then no cycle, if parent == child =>cycle exists
	vis[u] = true;
	for(int i=0; i<adj[u].size(); i++){
		int child = adj[u][i];
		if(vis[child] == false){
			if(dfs(adj, child, u)){
				return true;
			}
		}
		else if(vis[child] == true && child != p){
			return true;
		}
	}
	return false;
}
bool isCyclic(vector<int> adj[], int V){
	vis.clear();
	vis.resize(V, false);
	for(int i=0; i<V; i++){
		if(!vis[i]){
			if(dfs(adj, i, -1)){
				return true;
			}
		}
	}
	return false;
}