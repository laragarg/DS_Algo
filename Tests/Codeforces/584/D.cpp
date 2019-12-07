//Use graph
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, k;
	cin>>n>>k;
	//vector<int>s(n+1, 1);
	map<pair<int, int> , int> m;
	int count = 0;
	set<int> dist;
	for(int i=0; i<k; i++){
		int x, y;
		cin>>x>>y;
		if(m.find({x, y}) != m.end() || m.find({y, x}) != m.end()){
			count++;
		}
		else{
			m[{x, y}] = 1;
			set.insert(x);
			set.insert(y);
		}	
	}
	int ans = set.size() - 1 - count;
	cout<<ans<<endl;
	return 0;
}