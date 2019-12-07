//Can be used to find largest connected component after every insertion
#include<bits/stdc++.h>
using namespace std;
vector<int> id;
vector<int>sz;
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
        id[root_b] = root_a;
        sz[root_a] += sz[root_b];
        sz[root_b] = 0;
    }
    else{
        id[root_a] = root_b;
        sz[root_b] += sz[root_a];
        sz[root_a] = 0;
    }
    return;
}
int main(){
    int n, m;
    cin>>n>>m;
    id.clear();
    id.resize(n+1);
    sz.clear();
    sz.resize(n+1, 1);
    for(int i=1; i<=n; i++){
        id[i] = i;
    }
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        union1(a, b);
        vector<int>temp = sz;
        temp[0] = 0;
        sort(temp.begin(), temp.end());
        for(int i=1; i<=n; i++){
            if(temp[i]){
                cout<<temp[i]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}