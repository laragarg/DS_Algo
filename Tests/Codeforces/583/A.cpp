#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll n;
	cin>>n;
	ll d;//price of one dollar in rupees
	cin>>d;
	ll e;//price of one euro in rupees
	cin>>e;
	e = 5*e;
	ll n1 = n/d;
	ll n2 = n/e;
	ll ans = INT_MAX;
	for(ll i=0; i<=n1; i++){
		ll j = 0;
		while(j <= n2){
			ll var = n - ( (i*d) + (j*e));
			if(var < 0){
				n2 = j;
				break;
			}
			if(var == 0){
				cout<<0<<endl;
				return 0;
			}
			if(var>0 && var<ans){
				ans = var;
			}
			j++;
		}
	}
	cout<<ans<<endl;
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll n,d,e;
	cin>>n>>d>>e;
	e = 5*e;
	if(n%d == 0 || n%e == 0){
		cout<<0<<endl;
		return 0;
	}
	ll ans = n - (n/d)*d;
	for(ll x = 0; x<=n/d; x++){
		ll y = (n - d*x)/e;
		ans = min(ans, (n - d*x - e*y));
	}
	cout<<ans<<endl;
	return 0;
}

