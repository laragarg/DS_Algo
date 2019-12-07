#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> A(n);
	for(int i=0; i<n; i++){
		cin>>A[i];
	}
	sort(A.begin(), A.end());
	vector<bool>vis(n, false);
	int ans = 0;
	for(int i=0; i<n; i++){
		if(vis[i]){
			continue;
		}
		ans++;
		int a = A[i];
		vis[i] = true;
		for(int j=i+1; j<n; j++){
			if(A[j] % a == 0 && vis[j] == false){
				vis[j] = true;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}