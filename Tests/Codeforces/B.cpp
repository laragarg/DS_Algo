#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n, x;
		cin>>n>>x;
		ll diff = 0;
		ll maxm = INT_MIN;
		for(ll i=0; i<n; i++){
			ll a, b;
			cin>>a>>b;
			if(a - b >= diff){
				diff = a - b;
			}
			maxm = max(a, maxm);
		}
		if(maxm >= x){
			cout<<1<<endl;
			continue;
		}
		if(diff == 0){
			cout<<-1<<endl;
			continue;
		}
		x = x - maxm;
		ll count = x/diff;
		ll rem = x%diff;
		if(rem == 0){
			cout<<(count + 1)<<endl;
		}
		else{
			cout<<(count + 2)<<endl;
		}
	}
	return 0;
}