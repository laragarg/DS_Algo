#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void func(vector<vector<ll> > &A, vector<pair<ll, ll> > &moves, vector<vector<bool> > &vis, ll a, ll b){
	if(A[a+1][b]==1&&A[a][b+1]==1&&A[a+1][b+1]==1){
		vis[a][b] = true;
		vis[a+1][b] = true;
		vis[a][b+1] = true;
		vis[a+1][b+1] = true;
		moves.push_back({a, b});
	}
	return;
}
int main(){
	ll n, m;
	cin>>n>>m;
	vector<vector<ll> > A(n, vector<ll>(m));
	ll c0 = 0;
	for(ll i=0; i<n; i++){
		for(ll j=0; j<m; j++){
			cin>>A[i][j];
			if(A[i][j]==0){
				c0++;
			}
		}
	}
	if(c0==n*m){
		cout<<0<<endl;
		return 0;
	}
	vector<vector<bool> > vis(n, vector<bool>(m, false));
	vector<pair<ll, ll> >moves;
	for(ll i=0; i<n-1; i++){
		for(ll j=0; j<m-1; j++){
			if(A[i][j]==1){
				func(A, moves, vis, i, j);
			}
		}
	}
	for(ll i=0; i<n; i++){
		for(ll j=0; j<m; j++){
			if(A[i][j]==1&&vis[i][j]==false){
				cout<<-1<<endl;
				return 0;
			}
		}
	}
	cout<<moves.size()<<endl;
	for(ll i=0; i<moves.size(); i++){
		ll a = moves[i].first + 1;
		ll b = moves[i].second + 1;
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}