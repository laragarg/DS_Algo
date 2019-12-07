#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<pair<int, int> > A(n);
	for(int i=0; i<n; i++){
		cin>>A[i].first;
		A[i].second = i;
	}
	vector<pair<int, int> >B = A;
	sort(B.begin(), B.end());
	int ans = 0;
	vector<bool> vis(n, false);
	for(int i=0; i<n; i++){
		if(A[i].second == B[i].second || vis[i]){
			vis[i] = true;
			continue;
		}
		else{
			int j = B[i].second;
			vis[i] = true;
			int nodes = 1;
			while(!vis[j]){
			 //   cout<<"j = "<<j<<endl;
			 //   cout<<"here"<<endl;
				vis[j] = true;
				j = B[j].second;
				// cout<<"j = "<<j<<endl;
				nodes++;
			}
			ans += nodes - 1;
		}
	}
	cout<<"ans = "<<ans<<endl;
	return 0;
}