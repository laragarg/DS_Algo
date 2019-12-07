#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin>>n>>m;
	vector<int> h(n);
	vector<int> w(m);
	vector<vector<int> >A(n, vector<int>(m, 0));
	for(int i=0; i<n; i++){
		cin>>h[i];
		for(int j=0; j<h[i]; j++){
			A[i][j] = 1;
		}
	}
	for(int j=0; <m; j++){
		cin>>w[j];
		for(int i=0; i<w[j]; i++){
			// if(A[i][0] == 0){
			// 	cout<<0<<endl;
			// 	return 0;
			// }
			if(h[i] == j){
				cout<<0<<endl;
				return 0;
			}
			else{
				A[i][j] = 1;
				// cout<<0<<endl;
				// return 0;
			}
		}
	}
	// int count = 0;
	int ans = 1;
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			if(A[i][j] == 1){
				continue;
			}
			else{
				if(h[i] == j || w[j] == i){
					continue;
				}
				else{
					ans = (ans*2) % (1000000007);
				}
			}
		}
	}
	// int ans = (int)pow(2, count) % (1000000007);
	cout<<ans % 1000000007<<endl;
	return 0;
}