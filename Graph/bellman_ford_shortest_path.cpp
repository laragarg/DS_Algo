//Here graph is represented by connected edges, not the usual vertex method
//edge traversal
//Source is given
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    vector<pair< int, pair<int, int> > >edges(m);//source, (destination, edge_weight)
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        edges[i].first = c;
        edges[i].second.first = a;
        edges[i].second.second = b;
    }
    vector<int> dis(n+1, INT_MAX);
    dis[1] = 0;
    for(int i=0; i<n-1; i++){//just to iterate n-1 times
        int f = 1;
        for(int j=0; j<m; j++){//iterate n-1 times over the same set of edges
            int edge_wt = edges[j].first;
            int u = edges[j].second.first;
            int v = edges[j].second.second;
            dis[v] = min(dis[v], dis[u] + edge_wt);
            if(dis[v] == dis[u] + edge_wt){//i.e. the value has been changed
                f = 0;
            }
        }
        if(f == 1){//i.e. the value didn't change for any vertex 
            break;
        }
    }

    //iterate one more time now to detect whether there is a negative cycle or not
    for(int i=2; i<dis.size(); i++){
        cout<<dis[i]<<" ";
    }
    cout<<endl;
        
    return 0;
}