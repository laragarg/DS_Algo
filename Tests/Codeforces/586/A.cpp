#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll n;
	cin>>n;
	string s;
	cin>>s;
	// ll zeroes = 0;
	// ll ones = 
	vector<ll> A; 
	for(ll i=0; i<n; i++){
		if(s[i] == 'z'){
			A.push_back(0);
			//zeroes++;
		}
		if(s[i] == 'n'){
			A.push_back(1);
		}
	}
	sort(A.begin(), A.end());
	reverse(A.begin(), A.end());
	for(int i=0; i<A.size(); i++){
		cout<<A[i];
	}
	cout<<endl;
	//ll x = zeroes + ones;
	// ll ans;
	// for(ll i=0; i<A.size(); i++){
	// 	ans = ans*2 + A[i];
	// }
	// cout<<ans<<endl;
	return 0;
}