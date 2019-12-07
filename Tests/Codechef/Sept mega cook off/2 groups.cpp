#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	// speed();
	int t;
	cin>>t;
	int a,b,c;
	while (t--) {
		cin>>a>>b>>c;
		if(a + b + c < 2){
			cout<<"NO"<<"\n";
			continue;
		}
		int x = a % 2;
		int y = b % 2;
		int z = c % 2;
		int sum = x*1 + y*2 + z*3;
		if(sum % 2 != 0){
			cout<<"NO"<<"\n";
			continue;
		}
		if(z == 1 && x == 1 && y == 0) {
			if(a >= 3 || b >= 2) {
				cout<<"YES"<<"\n";
				continue;
			}
		}
		if(y == 1 && z == 0 && x == 0) {
			if(a >= 2 || (b >= 3 && c >= 2)) {
				cout<<"YES"<<"\n";
				continue;
			}
		}
		if(x == 0 && y == 0 && z == 0){
		    cout<<"YES"<<"\n";
		    continue;
		}
		if(x == 1 && y == 1 && z == 1) {
			cout<<"YES"<<"\n";
			continue;
		}
		cout<<"NO"<<"\n";

	}
	return 0;
}