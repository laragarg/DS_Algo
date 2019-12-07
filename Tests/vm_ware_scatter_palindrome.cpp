#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n = s.size();
	vector<vector<int> >A(26, vector<int>(n, 0));
	for(int i=0; i<n; i++){
		char x = s[i];
		// int temp = A[x - 'a'][i];
		for(int j=i; j<n; j++){
			A[x - 'a'][j]++;
		}
		// A[x - 'a'][i]++;
	}
	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int len = j - i + 1;
			bool f = 0;
			int k = 0;
			for(k; k<26; k++){
				if(i > 0){
					if( (A[k][j] - A[k][i - 1]) % 2 != 0){
						if(len % 2 == 0){
							break;
						}
						else{
							if(f == 1){
								break;
							}
							else{
								f = 1;
							}
						}
					}	
				}
				else{
					if( (A[k][j]) % 2 != 0){
						if(len % 2 == 0){
							break;
						}
						else{
							if(f == 1){
								break;
							}
							else{
								f = 1;
							}
						}
					}
				}
			}
			if(k == 26){
				ans++;
			}
		}
	}
	ans += n;
	cout<<"ans = "<<ans<<endl;
	return 0;
}