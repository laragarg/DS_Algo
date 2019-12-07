#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >g;
int n, m;
int bfs(){
    vector<int> vis(n+1, false);
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(g[i].size() == 1){
            q.push(i);
            vis[i] = true;
        }
    }
    int ans = 0;
    int level = 0;
    while(!q.empty()){
        // cout<<"here";
        int sz = q.size();
        // cout<<"level = "<<level<<endl;
        if(level % 2 != 0){
            cout<<"level = "<<level<<" ";
            cout<<"sz = "<<sz<<endl;
            ans += sz;
        }
        // cout<<"level = "<<level<<endl;
        for(int i=0; i<sz; i++){
            int temp = q.front();
            q.pop();
            vis[temp] = true;
            // cout<<"temp = "<<temp<<endl;
            for(int j=0; j<g[temp].size(); j++){
                if(!vis[g[temp][j]]){
                    vis[g[temp][j]] = true;
                    // cout<<"child = "<<g[temp][i]<<" ";
                    q.push(g[temp][j]);
                }
            }
        }
        level++;
    }
    return ans;
}
int main(){
    cin>>n;
    cin>>m;
    g.clear();
    g.resize(n + 1);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = bfs();
    cout<<"ans = "<<ans<<endl;
    return 0;
}