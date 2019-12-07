#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n, k;
	cin>>n>>k;
	vector<int> A(n);
	unordered_map<int, int>ma;
	for(int i=0; i<n; i++){
		cin>>A[i];
		ma[A[i]]++;
	}
	int sz = ma.size();
	int ans1 = min(sz, min(n, k));
	ma.clear();
	queue<int> q;
	for(int i=0; i<n; i++){
		if(ma.find(A[i]) == ma.end()){
			q.push(A[i]);
			ma[A[i]]++;
		}
		else{
			ma[A[i]]++;
		}
		if(q.size() > k){
			while(q.size() > k){
				int x = q.front();
				q.pop();
				ma.erase(x);
			}
		}
	}
	vector<int> ans;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		ans.push_back(x);
	}
	reverse(ans.begin(), ans.end());
	cout<<ans1<<endl;
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}