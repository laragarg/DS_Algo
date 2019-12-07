#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        if(n < r){
            cout<<0<<endl;
            continue;
        }
        int ans = 1;
        r = min(r, (n-r));
        for(int i=1; i<=r; i++){
            ans = ((ans % mod) * ( (n-r+i) % mod)) % mod;
            ans = ((ans%mod) / (i % mod)) % mod;
        }
        cout<<ans % mod<<endl;
    }
	return 0;
}