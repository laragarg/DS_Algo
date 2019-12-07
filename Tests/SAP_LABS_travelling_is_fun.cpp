//SAP Labs travelling is fun
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph();
void dfs(int node, int count, vector<int> &cc){
    if(cc[node])
        return;
    cc[node]=count;
    for(int i=0;i<graph[node].size();++i)
        dfs(graph[node][i],count,cc);
}

int main(){
    int n, g, q;
    cin>>n>>g>>q;
    vector<int> A(q), B(q);
    for(int i=0; i<q; ++i){
        cin>>A[i];
    }
    cin>>q;
    for(int i=0;i<q;++i){
        cin>>d[i];
    }
    if(g == n){                    
        for(int i=0;i<q;++i){
            cout<<0<<endl;
        }
        return 0;
    }
    if(g==0){                       
        for(int i=0;i<q;++i){
            cout<<1<<endl;
        }
        return 0;
    }
    graph.clear();
    graph.resize(n+1, 0);
    for(int i=g+1;i<=n;++i){
        for(int j=2;j*i<=n;++j){       //all the multiples of "i" will have i as a common divisor
            int a=j*i;
            graph[i].push_back(a);          
            graph[a].push_back(i);
        }
    }
    vector<int> cc(n+1);              //find all connected components, will suffice for all queries.
    int connected_component=0;
    for(int i=1; i<=n; ++i){
        if(cc[i]==0){
            connected_component++;
            dfs(i,connected_component,cc);
        }
    }
    for(int i=0; i<q; ++i){
        if(cc[s[i]]==cc[d[i]])
            cout<<1;
        else
            cout<<0;
        cout<<endl;
    }
    return 0;
}
