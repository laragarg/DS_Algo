#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll n, t;
	cin>>n>>t;//buses and arrival time
	vector<pair<ll, ll> >A;
	ll ans = INT_MAX;
	ll great = 0;
	for(ll i=0; i<n; i++){
		ll a, b;//first bus and interval time
		cin>>a>>b;
		A.push_back({a, b});
		if(a==t && ans == INT_MAX){
			ans = i + 1;
		}
		if(a>t){
			great++;
		}
	}
	if(ans!=INT_MAX){
		cout<<ans<<endl;
		return 0;
	}
	if(great==n){
		ll temp = INT_MAX;
		for(ll i=0; i<n; i++){
			temp = min(ans, A[i].first);
			if(temp == A[i].first){
				ans = i + 1;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	ll wait = INT_MAX;
	for(ll i=0; i<n; i++){
		ll a = A[i].first;
		ll diff = A[i].second;
		
		while(a<t){
			a += diff;
		}
		//cout<<"a = "<<a<<"; ";
		if(a == t){
			ans = i + 1;
			cout<<ans<<endl;
			return 0;
		}
		else{
			wait = min(wait, a - t);
			if(wait == a - t){
				ans = i + 1;
			}
			//cout<<"wait = "<<wait<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}