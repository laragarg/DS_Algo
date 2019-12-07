#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod (1000000000 + 7)
// vector<vector<int> >g;
vector<int> id;
vector<int> sz;
int root(int x){
    while(id[x] != x){
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}
void union1(int a, int b){
    int root_a = root(a);
    int root_b = root(b);
    if(sz[root_a] >= sz[root_b]){
        sz[root_a] += sz[root_b];
        sz[root_b] = 0;
        id[root_b] = root_a;
    }
    else{
        sz[root_b] += sz[root_a];
        sz[root_a] = 0;
        id[root_a] = root_b;
    }
    return;
}
signed main(){
    int n, m;
    cin>>n>>m;
    // g.clear();
    id.clear();
    sz.clear();
    id.resize(n+1, 0);
    sz.resize(n+1, 1);
    for(int i=1; i<=n; i++){
        id[i] = i;
    }
    // g.resize(n+1);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        // g[a].push_back(b);
        // g[b].push_back(a);
        if(root(a) != root(b)){
            union1(a, b);
        }
    }
    vector<int> temp;
    for(int i=0; i<=n; i++){
        if(sz[root(i)] != 0){
            temp.push_back(sz[root(i)]);//size of connected component
        }
    }
    
    return 0;
}
