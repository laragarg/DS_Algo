#include<bits/stdc++.h>
using namespace std;
vector<int> A(7);
vector<vector<vector<int> > >dp;
int func(int last, int countlast, int n){
	if(n == 0){
		return 1;
	}
	if(dp[last][countlast][n] != -1){
		return dp[last][countlast][n];
	}
	int res = 0;
	for(int i=1; i<=6; i++){
		if(i == last && countlast + 1 > A[last]) continue;
		if(i == last){
			res += func(last, countlast + 1, n-1);
		}
		else{
			res += func(i, 1, n-1);
		}
		// cout<<"res = "<<res<<endl;
	}
	return dp[last][countlast][n] = res;
}
int main(){
	int n;
	cin>>n;
	A.clear();
	A.resize(7);
	int maxc = 0;
	for(int i=1; i<=6; i++){
		cin>>A[i];
		maxc = max(maxc, A[i]);
	}
	dp.clear();
	dp.resize(7, vector<vector<int> >(maxc + 1, vector<int>(n + 1, -1)));
	int ans= 0;
	for(int i=1;i<=6;i++)
		ans += func(i, 1, n-1);
	cout<<"ans = "<<ans<<endl;
	return 0;
}