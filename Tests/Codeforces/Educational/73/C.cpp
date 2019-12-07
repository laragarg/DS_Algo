#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll q;
	cin>>q;
	while(q--){
		ll c, m, x;
		cin>>c>>m>>x;
		if(c == 0 || m == 0){
			cout<<0<<endl;
			continue;
		}
		ll ans = 0;
		if(x != 0){
			ans = min(x, min(c, m));
			if(ans == x){
				c = c - x;
				m = m -x;
			}
			else if(ans == c || ans == m){
				cout<<ans<<endl;
				continue;
			}
		}
		ll g = 0, h = 0;
		if(c > m){
			g = min(c/2, m);
		}
		else if(c < m){
			g = min(c, m/2);
		}
		else{
			g = min(c/2, m);
			h = min(c, m/2);
		}
// 		cout<<"g = "<<g<<endl;
// 		cout<<"h = "<<h<<endl;
		// ll g = min(c/2, m);
		// ll h = min(c, m/2);
		ans += g + h;
		cout<<ans<<endl;
	}
	return 0;
}