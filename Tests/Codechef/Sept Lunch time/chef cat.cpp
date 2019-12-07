#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int  n, m;
		cin>>n>>m;
		vector<int> A(m);
		unordered_map<int, int> ma;
		int f = 0;
		for(int i=0; i<m; i++){
			// cin>>A[i];
			int a;
			cin>>a;
			if(f){
				continue;
			}
			ma[a]++;
			if(ma[a] == 1){
				continue;
			}
			int x = ma[a];
			for(int i=1; i<=n; i++){
				if(ma.find(i) == ma.end()){
					cout<<"NO"<<endl;
					f = 1;
					break;
				}
				else if(x - ma[i] > 1){
					cout<<"NO"<<endl;
					f = 1;
					break;
				}
			}
		}
		if(f){
			continue;
		}
		else{
			cout<<"YES"<<endl;
		}

	}
	return 0;
}