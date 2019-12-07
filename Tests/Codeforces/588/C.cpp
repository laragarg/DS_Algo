#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	// speed();
	int n,m;
	cin>>n>>m;
	if(m == 0) {
		cout<<0<<endl;
		return 0;
	}
	vector<vector<int> >g(n, vector<int>(n, 0));
	vector<int> deg(n, 0);
	for(int i=0; i<m; i++) {
		int a, b;
		cin>>a>>b;
		g[a-1][b-1] = 1;
		g[b-1][a-1] = 1;
		deg[a-1]++;
		deg[b-1]++;
	}
	if(n <= 6) {
		cout<<m<<endl;
		return 0;
	}
	int a = 0, b = 1, maxm = -1;
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			int u = 0;
			for(int k=0; k<n; k++) {
				if(g[i][k] == 1 && g[j][k] == 1) {
					continue;
				}
				u++;
			}
			maxm = max(maxm, u);
			if(maxm == u){
				a = i;
				b = j;
			}
		}
	}
	int ans = m - (n - maxm);
	cout<<ans<<endl;
	return 0;

}