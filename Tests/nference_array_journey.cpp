#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int> A;
vector<int>dp;
int func(int in){
	if(in >= n){
		return 0;
	}
	if(in == n-1){
		return A[n-1];
	}
	if(dp[in] != -1){
		return dp[in];
	}
	int res = 0;
	for(int i=1; i<=k; i++){
        res = max(res, func(in + i) + A[in]);
	}
	return dp[in] = res;
}
int main(){
	// int n;
	cin>>n;
	cin>>k;
	// vector<int> A(n);
	A.clear();
	A.resize(n);
	for(int i=0; i<n; i++){
		cin>>A[i];
	}
	dp.clear();
	dp.resize(n, -1);
	int ans = func(0);
	cout<<"ans = "<<ans<<endl;
	return 0;
}





#include<bits/stdc++.h>
using namespace std;
int main(){
	int maxm = 1;
	vector<int> arr = {-1,8,6,0,7,3,8,9,-1,6,1};
	int n = arr.size();
	map<int, int>vis;
	stack<int>st;
	for(int i=0; i<n; i++){
		int a = i;
		int count = 1;
		while(a > -1){
		    if(vis.find(a) != vis.end()){
		        count = vis[a]+1;
		        break;
		    }
			st.push(a);
			a = arr[a];
		}
		while(!st.empty()) {
			a = st.top();
			cout<<a<<" "<<count<<endl;
			vis[a] = count;
			maxm = max(maxm, count);
			count++;
			st.pop();
		}
		cout<<endl;
	}
    cout<<maxm<<endl;
	return 0;
}