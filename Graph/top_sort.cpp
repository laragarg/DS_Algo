//Simple dfs based solution
#include<bits/stdc++.h>
using namespace std;
void topSort(vector<vector<int> >&g, vector<int> &vis, stack<int>&s, int v){
    vis[v] = true;
    for(int i = 0; i<g[v].size(); i++){
        /*if(v==3){
            cout<<"val = "<<g[v][i]<<endl;
        }*/
        if(!vis[g[v][i]]){
            topSort(g, vis, s, g[v][i]);
        }
    }
    s.push(v);
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int> >g(m);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        //cout<<"a="<<a<<", b="<<b<<endl;
        g[a].push_back(b);
    }
    stack<int> s;
    vector<int> vis(n+1, false);
    for(int i=1; i<=n; i++){
        //cout<<"here"<<endl;
        if(!vis[i]){
            topSort(g, vis, s, i);
        }
    }
    //cout<<"here"<<endl;
    vector<int> ans;
    while(!s.empty()){
        int x = s.top();
        s.pop();
        ans.push_back(x);
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}