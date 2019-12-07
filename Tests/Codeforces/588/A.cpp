#include<bits/stdc++.h>
using namespace std;
int main(){
	// vector<int> A(4)
	int a, b, c, d;
	cin>>a>>b>>c>>d;
	if(a == (b + c + d)){
		cout<<"YES"<<endl;
		return 0;
	}
	if(b == (a + c + d)){
		cout<<"YES"<<endl;
		return 0;
	}
	if(c == (a + b + d)){
		cout<<"YES"<<endl;
		return 0;
	}
	if(d == (a + b + c)){
		cout<<"YES"<<endl;
		return 0;
	}
	if(a + b == (c + d)){
		cout<<"YES"<<endl;
		return 0;
	}
	if(a + c == (b + d)){
		cout<<"YES"<<endl;
		return 0;
	}
	if(a + d == (b + c)){
		cout<<"YES"<<endl;
		return 0;
	}
	cout<<"NO"<<endl;
	return 0;
}