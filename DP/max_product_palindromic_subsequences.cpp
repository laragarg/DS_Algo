#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n = s.size();
	vector<vector<int> >dp(n, vector<int>(n, 1));
	for(int i=0; i<n; i++){
		dp[i][i] = 1;
	}
	for(int i=0; i<n-1; i++){
		if(s[i] == s[i+1]){
			dp[i][i+1] = 2;
		}
	}
	for(int gap=2; gap<n; gap++){
		for(int i=0, j=gap; i<n, j<n; i++, j++){
			if(s[i] == s[j]){
				dp[i][j] = dp[i+1][j-1] + 2;
			}
			else{
				dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
			}
		}
	}
	int ans = 1;
	for(int i=0; i<n-1; i++){
		int a = dp[0][i];
		int b = dp[i+1][n-1];
		ans = max(ans, a*b);
	}
	cout<<ans;
	return 0;
}