#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	if(s[0] == 'h'){
		s.insert(s.begin() + 4, ':');
		s.insert(s.begin() + 5, '/');
		s.insert(s.begin() + 6, '/');
		int n = s.size();
		int i = 7;
		while(i < n - 1){
			if(i != 7 && s[i] == 'r' && s[i+1] == 'u'){
				break;
			}
			// cout<<"i = "<<i<<endl;
			i++;
		}
		s.insert(s.begin() + i, '.');
		i += 3;
		// cout<<"i = "<<i<<endl;
		if(i == s.size()){
			cout<<s<<endl;
		}
		else{
			s.insert(s.begin() + i, '/');
			cout<<s<<endl;
		}
	}
	else{
		s.insert(s.begin() + 3, ':');
		s.insert(s.begin() + 4, '/');
		s.insert(s.begin() + 5, '/');
		int n = s.size();
		int i = 6;
		while(i < n - 1){
			if(i != 6 && s[i] == 'r' && s[i+1] == 'u'){
				break;
			}
			// cout<<"i = "<<i<<endl;
			i++;
		}
		s.insert(s.begin() + i, '.');
		i += 3;
		if(i == s.size()){
			cout<<s<<endl;
		}
		else{
			s.insert(s.begin() + i, '/');
			cout<<s<<endl;
		}
	}
	return 0;
}