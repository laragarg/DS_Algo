#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int> > >g;
unordered_map<int, unordered_map<int, int> >W;
void dfs(int v, int w, vector<int> &gut, vector<bool> &vis){
	gut.push_back(v);
	vis[v] = true;
	int sz = g[v].size();
	for(int i=0; i<sz; i++){
		int child = g[v][i].first;
		int wt = g[v][i].second;
		if(!vis[child] && wt == w){
			dfs(child, w, gut, vis);
		}
	}
	return;
}
int main(){
	int n, m;
	cin>>n>>m;
	vector<int> A(m);
	for(int i=0; i<m; i++){
		cin>>A[i];
	}
	cin>>m;
	vector<int> B(m);
	for(int i=0; i<m; i++){
		cin>>B[i];
	}
	cin>>m;
	vector<int> C(m);
	for(int i=0; i<m; i++){
		cin>>C[i];
	}
	g.clear();
	g.resize(n + 1);
	for(int i=0; i<m; i++){
		int a = A[i];
		int b = B[i];
		int wt = C[i];
		W[wt][a] = 1;
		W[wt][b] = 1;
		g[a].push_back({b, wt});
		g[b].push_back({a, wt});
	}
	int ans = INT_MIN;
	int maxsz = 0;
	for(int i=0; i<m; i++){
		int wt = C[i];
		vector<bool> vis(n+1, false);
		for(int i=1; i<=n; i++){
			vector<int> gut;
			if(W[wt].find(i) != W[wt].end()){
				if(!vis[i]){
					dfs(i, wt, gut, vis);
				}
			}
			int currsz = gut.size();
			sort(gut.begin(), gut.end());
			maxsz = max(maxsz, currsz);
			if(maxsz == currsz){
				ans = max(ans, gut[currsz - 1] * gut[currsz - 2]);
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
4
5
1
1
2
2
2
5
2
2
3
3
4
5
1
2
1
3
3
*/