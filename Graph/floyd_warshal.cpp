#include<bits/stdc++.h>
using namespace std;
// #define int long long
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int> >g(n, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>g[i][j]; // i to j ka weight
            }
        }
        for(int k=0; k<n; k++){
        	for(int i=0; i<n; i++){
        		for(int j=0; j<n; j++){
        			g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        		}
        	}
        }
        for(int i=0; i<n; i++){
        	for(int j=0; j<n; j++){
        		if(g[i][j] == 10000000){
        			cout<<"INF"<<" ";
        		}
        		else{
        			cout<<g[i][j]<<" ";
        		}
        	}
        	cout<<endl;
        }
        // cout<<endl;
    }
	return 0;
}