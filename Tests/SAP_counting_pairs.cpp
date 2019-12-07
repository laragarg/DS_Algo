#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, k;
	cin>>n;
	// k = -(k);
	vector<int> A(n);
	unordered_map<int, int> hash;
	set<pair<int, int> >st;
	int ans = 0;
	for(int i=0; i<n; i++){
	    cin>>A[i];
	}
	cin>>k;
	sort(A.begin(), A.end());
	for(int i=n-1; i>=0; i--){
		int a = A[i];
// 		cin>>a;
		if(hash.find(k + a) != hash.end() && st.find({a, k + a}) == st.end()){
		  //  cout<<"a = "<<a<<endl;
			ans++;
			st.insert({a, k + a});
		}
		hash[a]++;
	}
	cout<<"ans = "<<ans<<endl;
	return 0;
}