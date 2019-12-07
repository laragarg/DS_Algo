#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n = s.size();
	int wendy = 0, bob = 0;
	int i = 0;
	while(i < n){
		int j = i;
		int len = 0;
		// if(s[j] == 'w'){
			while(j < n - 1 && s[j] == s[j+1]){
				j++;
			}
			len = j - i + 1;
		// }
		if(s[i] == 'w' && len >= 3){
			wendy += len - 2;
		}
		else if(s[i] == 'b' && len >= 3){
			bob += len - 2;
		}
		i = j + 1;
	}
	if(wendy > bob){
		cout<<"Wendy";
	}
	else{
		cout<<"Bob";
	}
	return 0;
}