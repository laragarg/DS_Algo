#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n = s.size();
	vector<int> v(26, 0);
	for(int i=0; i<n; i++){
		v[s[i] - 'a']++;
	}
	for(int i=0; i<n; i++){
		char x = s[i];
		if(v[x - 'a'] == 0){
			continue;
		}
		else{
			cout<<x<<v[x - 'a'];
			v[x - 'a'] = 0;
		}
// 		cout<<v[x - 'a']<<" ";
	}
	return 0;
}