#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	int n;
	cin>>n;
	string str;
	cin>>str;
	if(n%2!=0){
		cout<<"NO"<<endl;
		return 0;
	}
	int i = 0;
	int count = 0;
	stack<char> s;
	int a = 0;
	int b = 0;
	while(i < n){
		char x = str[i];
		if(x == ')'){
			b++;
			if(!s.empty() && s.top() == '('){
				s.pop();
			}
			else{
				count++;
			}
		}
		else{
			a++;
			s.push(x);
		}
		if(count > 1){
			cout<<"NO"<<endl;
			return 0;
		}
		i++;
	}
	if(a!=b){
		cout<<"NO"<<endl;
	}
	else if(count<=1){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}