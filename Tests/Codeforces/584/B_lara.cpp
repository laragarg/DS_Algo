#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<pair<int, int> >A(n);
	// int ans = 0;
	//int curr = 0;
	for(int i=0; i<n; i++){
		int a, b;
		cin>>a>>b;
		A[i] = {a, b};
		// if(s[i] == '1'){
		// 	curr++;
		// }
	}
	//sort(A.begin(), A.end());
	int ans = 0;
	for(int t=0; t<1000; t++){
		int curr = 0;
		for(int i=0; i<n; i++){
			int interval = A[i].first;
			int start = A[i].second;
			if(start == t || (t >= start && (t - start) % interval == 0)){
				if(s[i] == '1'){
					s[i] = '0';
				}
				else{
					curr++;
					s[i] = '1';
				}
			}
			else{
				if(s[i] == '1'){
					curr++;
				}
			}
		}
		ans = max(ans, curr);
	}
	cout<<ans<<endl;
	return 0;
}