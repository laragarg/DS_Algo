#include<bits/stdc++.h>
using namespace std;
pair<int, int> distinct(int a){
	int ans = 0;
	unordered_map<int, int> m;
	while(a){
		ans++;
		m[a%10]++;
		a = a/10;
	}
	return {m.size(), ans};
}
int main(){
	int l, r;
	cin>>l>>r;
	if(l > r){
		l = l ^ r;
		r = r ^ l;
		l = l ^ r;
	}
	while(l <= r){
		int dist = distinct(l).first;
		int sz = distinct(l).second;
		if(dist == sz){
			cout<<l<<endl;
			return 0;
		}
		l++;
	}
	cout<<-1<<endl;
	return 0;
}