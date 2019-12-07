#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define sd(t) scanf("%d",&t)
#define pd(t) printf("%d\n",t)
#define slld(t) scanf("%lld",&t)
#define plld(t) printf("%lld\n",t)
#define For(i,n) for(ll i=0;i<n;i++)
#define bll __builtin_popcountll
#define speed ios::sync_with_stdio(false); cin.tie(0)
using namespace std;
 
vector<ll> v[100005];
ll visited[100005]={0};
ll ans=0;
 
void dfs(ll u)
{
    visited[u]=1;
    for(auto j:v[u])
    {
        if(visited[j]==0)
        {
            dfs(j);
            ans++;
        }
    }
}
 
 
int main()
{
	speed;
    ll n,k;
    cin>>n>>k;
    for(ll i=0;i<k;i++)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for(ll i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            dfs(i);
        }
    }
    cout<<k-ans;
    return 0;
           
}