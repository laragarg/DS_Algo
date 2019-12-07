#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;//ways to buy shares
	int m;//ways to sell shares
	int r;//initial money
	cin>>n>>m>>r;

	vector<int> vn(n, 0);
	vector<int> vm(m, 0);

	int minm=INT_MAX;
	int maxm=INT_MIN;
	for(int i=0; i<n; i++){
		cin>>vn[i];
		minm=min(minm, vn[i]);
	}

	for(int i=0; i<m; i++){
		cin>>vm[i];
		maxm=max(maxm, vm[i]);
	}

	int sh=r/minm;
	int final=sh*maxm + (r%minm);
	if(final>=r){
		cout<<final;
	}
	else{
		cout<<r;
	}
	return 0;
}