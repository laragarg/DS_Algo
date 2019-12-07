#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll n;
	cin>>n;
	vector<ll> A(n);
	map<ll, ll> m;
	int f = 0;
	for(ll i=0; i<n; i++){
		cin>>A[i];
		if(m.find(A[i])==m.end()){
			m[A[i]] = 1;
		}
		else{
			m[A[i]]++;
		}
		if(m[A[i]]>1){
			f = 1;
		}
	}
	if(f==0){
		cout<<0<<endl;
		return 0;
	}
	ll ans = 0;
	int l = -1;
	int r = -1;
	//map<ll, ll>m2;
	ll first = INT_MIN;
	for(ll i=0; i<n; i++){
		if(m[A[i]]>1){
			if(l == -1){
				if(first == INT_MIN){
					first = A[i];
				}
				else{
					flag = 1;
				}
			}
			else{
				r = i;	
			}
			
		}
	}
	ans = r - l + 1;
	cout<<ans<<endl;
	return 0;
}