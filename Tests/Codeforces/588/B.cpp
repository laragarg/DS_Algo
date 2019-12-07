#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n, k;
	cin>>n>>k;
	string st;
	cin>>st;
// 	cout<<"st = "<<st<<endl;
	if(n == 1 && k >= 1){
		cout<<0<<endl;
		return 0;
	}
	for(int i=0; i<n; i++){
		if(k <= 0){
			break;
		}
		char dig = st[i];
		if(i == 0){
		    if(st[i] != '1'){
			    st[i] = '1';
		        k--;
		    }
		}
		else{
		    if(st[i] != '0'){
			    st[i] = '0';
		        k--;
		    }
		}
	}
	cout<<st;
	return 0;
}