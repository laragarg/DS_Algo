#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll b, g, n;
	cin>>b;
	cin>>g;
	cin>>n;
	ll ans = n + 1;
	if(b>=n && g>=n){
		cout<<ans<<endl;
		return 0;
	}
	if(b >= n){
		ans = ans - (n - g);
		cout<<ans<<endl;
		return 0;
	}
	if(g >= n){
		ans = ans - (n - b);
		cout<<ans<<endl;
		return 0;
	}
	ans = ans - (n - g) - (n - b);
	cout<<ans<<endl;
	return 0;
}