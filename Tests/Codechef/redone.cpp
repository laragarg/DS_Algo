#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod= 1e9+7;
int main() {
	// your code goes here
	ll t;cin>>t;
	ll ans=5;
	ll dp[1000001];
	dp[1]=1;
	dp[2]=5;
	for(ll i=3;i<=1000000;i++)
	{
		dp[i]=dp[i-1]+i+dp[i-1]*i;
		dp[i]%=mod;
	}
	while(t--)
	{
		ll x;cin>>x;
		cout<<dp[x]<<endl;
	}
	return 0;
}
