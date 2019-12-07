#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll a, b, n;
		cin>>a>>b>>n;
		vector<ll> A;
		A.push_back(a);
		A.push_back(b);
		for(ll i=2; i<=n; i++){
			ll x = A[i-1]^A[i-2];
			A.push_back(x);
		}
		cout<<A[n]<<endl;
	}
	return 0;
}