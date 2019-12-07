#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	string s;
	cin>>s;
	ll n = s.size();
	ll set = 0;
	if(n == 1 && s[0] =='0'){
        cout<<0<<endl;
        return 0;
    }
	lli i = 0;
	while(i<n){
		if(s[i] == '1'){
			set1++;
		}
		i++;
	}
	ll k = (n-1)/2;
	if(set1==1&&(n-1)%2==0){
		cout<<k<<endl;
	}
	else{
		cout<<k+1<<endl;
	}
	return 0;
}
