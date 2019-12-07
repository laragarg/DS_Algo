//undirected graph, with each edge having weight = 6
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
void bfs(vector<vector<int> >&g, vector<int> &dis, int n, int s){   
    queue<PII>q;
    q.push({0,s});
    vector<int> vis(n+1, false);
    dis[s]=0;
    //int level = 0;
    while(!q.empty()){
        int sz = q.size();
        for(int i=0; i<sz; i++){
            PII temp = q.front();
            q.pop();
            int v = temp.second;//node number
            if(vis[v]){
                continue;
            }
            int neighbours = g[v].size();
            for(int i=0; i<neighbours; i++){
                int child = g[v][i]; 
                if(dis[v] + 1 < dis[child]){ //Core logic
                    dis[child]=dis[v] + 1;
                    q.push( {dis[child], child} );
                }
            }
            vis[v]=true;
        }
        
    }
    return;
}
int main(){
    int q;
    cin>>q;
    while(q--){
        int n, m;
        cin>>n>>m;
        vector<vector<int> >g(n+1);
        for(int i=0; i<m ;i++){
            int a, b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int s;//source node
        cin>>s;
        vector<int> dis(n+1, INT_MAX);
        bfs(g, dis, n, s);
        for(int i=1; i<=n; i++){
            if(i==s){
                continue;
            }
            if(dis[i]==INT_MAX){
                dis[i] = -1;
            }
            else{
                dis[i] = 6*dis[i];
            }
            cout<<dis[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
