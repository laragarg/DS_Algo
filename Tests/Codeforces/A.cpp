#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll a, b, c;
		cin>>a>>b>>c;
		//ll x = a;
		ll count = 0;
		if(c == 0){
			if(a > b){
				cout<<1<<endl;
			}
			else{
				cout<<0<<endl;
			}
			continue;	
		}
		a = a + c;
		if(a <= b){
			cout<<0<<endl;
			continue;
		}
		a = a - c;
		ll x = (b - a + c);
		if(x < 0){
			c++;
			cout<<c<<endl;
		}
		else{
		    x = x/2;
			cout<<c - x<<endl;
		}
	}
	return 0;
}