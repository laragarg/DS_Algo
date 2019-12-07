#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll n;
	cin>>n;
	vector<vector<ll> >A(n, vector<ll>(n, 0));
	vector<ll> temp;
	for(ll i=0; i<n; i++){
		for(ll j=0; j<n; j++){
			cin>>A[i][j];
		}
	}
	// temp = A[0];
	// temp.erase(temp.begin() + 0);
	vector<ll> ans;
	ll x = A[0][1]*A[0][2]/A[1][2];
	ll a = sqrt(x);
	cout<<a<<" ";
	for(ll j=1; j<n; j++){
		ll x = A[0][j]/a;
		cout<<x<<" ";
	}
	cout<<endl;
	return 0;
}