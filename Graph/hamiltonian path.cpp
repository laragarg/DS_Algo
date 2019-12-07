//to check whether hamiltonian path exists or not
//Definition : Permutation(order matters) of all the vertices such that there exists edge between every 2 consecutive vertices
//Or in other words, that path in the graph which traverses every node exactly once
#include<bits/stdc++.h>
using namespace std;
bool check(vector<vector<int> >&g, vector<int> &path, int v, int pos){//to check if there exists an edge between previous vertex and next candidate 
    for(int i=0; i<pos; i++){//return false if the vertex has already been considered
        if(path[i]==v){
            return false;
        }
    }

    int neighbour = path[pos-1];
    for(int i=0; i<g[neighbour].size(); i++){
        if(g[neighbour][i]==v){//return true if there exists an edge between previous vertex and next candidate
            return true;
        }
    }
    return false;
}

bool driver(vector<vector<int> >&g, vector<int> &path, int pos, int n){
    if(pos==n){
       return true;
    }
    for(int i=0; i<n; i++){//check vertices one by one for index pos
        if(check(g, path, i, pos)){
            path[pos] = i;
            if(driver(g, path, pos+1, n))
                return true;
            else 
                path[pos] = -1;
        }
    }
    return false;
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int> >g(n+1);//adjacency list
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    for(int i=0; i<n; i++) {
        vector<int> path(n, -1);
        path[0] = i;
        if(driver(g, path, 1, n)){//1 is the next index to be filled
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}