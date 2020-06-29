#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fl(i,n) for(ll i=0;i<n;i++)
#define repx(i,a,b) for(ll i=a;i<=b;i++)
#define PI 3.14159265
#define md 1000000007
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define all(a) a.begin(),a.end()
ll ar[1001][1001];

ll ncr(ll n, ll r){
    if(ar[n][r] != 0){
        return ar[n][r];
    }
    if(n == r || r == 0){
        return 1;
    }
    ar[n][r] = (ncr(n-1,r-1) + ncr(n-1,r))%md;
    return ar[n][r];
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,r;
        cin>>n>>r;
        if(n >= r)
            cout<<ncr(n,r)%md<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}
