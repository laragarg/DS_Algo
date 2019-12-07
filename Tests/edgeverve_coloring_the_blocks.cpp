#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int> >A;
vector<vector<int> >dp;
int func(int in, int prev){
	// if(in >= n){
	// 	return 0;
	// }
	if(dp[in][prev] != -1){
		return dp[in][prev];
	}
	if(in == n-1){
		int temp = INT_MAX;
		for(int i=0; i<3; i++){
			if(i == prev){
				continue;
			}
			temp = min(temp, A[in][i]);
		}
		return dp[in][prev] = temp;
	}
	int res = INT_MAX;
	for(int i=0; i<3; i++){
		if(i == prev){
			continue;
		}
		else{
			res = min(res, func(in+1, i) + A[in][i]);
		}
	}
	return dp[in][prev] = res;
} 
int main(){
	// int n;
	cin>>n;
	A.clear();
	A.resize(n, vector<int>(3));
	dp.clear();
	dp.resize(n, vector<int>(3, -1));
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			cin>>A[i][j];
		}
	}	
	int ans = INT_MAX;
	for(int i=0; i<3; i++){
		ans = min(ans, func(1, i) + A[0][i]);
	}
	cout<<"ans = "<<ans;
	return 0;
}	