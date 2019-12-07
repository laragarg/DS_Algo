#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>A(n);
	vector<int>B(n);
	for(int i=0; i<n; i++){
		cin>>A[i];
	}
	for(int i=0; i<n; i++){
		cin>>B[i];
	}
	unordered_map<int, vector<int> >hash;
	int ans = 0;
	int m;
	cin>>m;
	// vector<pair<int, int> > v(m);
	for(int i=0; i<m; i++){
		int a, b;
		cin>>a>>b;
		if(a <= b){
			swap(a, b);
		}
		hash[a].push_back(b);
	}
	int ans = 0;
	for(auto it=hash.begin(); it!=hash.end(); it++){
		int p = it->first;
		vector<int> temp = it->second;
		temp.push_back(p);
		unordered_map<int, int>temp;
		for(int i=0; i<temp.size(); i++){
			int in = temp[i];
			int a = A[in];
			if(temp.find(a) != temp.end()){
				temp.erase(a);
			}
			else{
				temp[a]++;
			}
			int b = B[in];
			if(temp.find(b) != temp.end()){
				temp.erase(b);
			}
			else{
				temp[b]++;
			}
		}
		ans += temp.size() / 2;
	}
	cout<<ans<<endl;
	return 0;
}