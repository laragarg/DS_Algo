#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >dis;
vector<vector<int> >A;
vector<vector<bool> >vis;
int n;
// int ans;
typedef pair<int, int> PII;
void dijkstra(){   
    priority_queue<pair<int, PII>, vector<pair<int, PII> >, greater<pair<int, PII> > > pq;
    pq.push({A[0][0], {0, 0}});
    // vector<int> vis(n+1, false);
    dis[0][0]=A[0][0];
    while(!pq.empty()){
        pair<int, PII> temp=pq.top();
        pq.pop();
        PII state = temp.second;
        int a = state.first;
        int b = state.second;
        // int v = temp.second;//node number
        if(vis[a][b]){
            continue;
        }
        vis[a][b]=true;
        for(int i=-1; i<=1; i++){
            int di = a + i;
            if(di < 0 || di >= n){
                continue;
            }
            for(int j=-1; j<=1; j++){
                int dj = b + j;
                if(dj < 0 || dj >= n){
                    continue;
                }
                if(abs(i) == abs(j)){
                    continue;
                }
                int wt = A[di][dj];
                if(!vis[di][dj] && dis[di][dj] > dis[a][b] + wt){
                    dis[di][dj] = dis[a][b] + wt;
                    pq.push({dis[di][dj], {di, dj}});
                }
            }
        }
    }
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        // ans = INT_MAX;
        dis.clear();
        A.clear();
        vis.clear();
        dis.resize(n, vector<int>(n, INT_MAX));
        A.resize(n, vector<int>(n, 0));
        vis.resize(n, vector<bool>(n, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>A[i][j];
            }
        }
        dijkstra();
        // ans = min(ans, dfs(0, 0, 0));
        cout<<dis[n-1][n-1]<<endl;
    }
    return 0;
}