//Replace every element with the least greater element on its right
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> A(n);
	for(int i=0; i<n; i++){
		cin>>A[i];
	}
	set<int>st;
	vector<int> ans(n);
	for(int i=n-1; i>=0; i--){
		int a = A[i];
		if(st.empty()){
		  //  cout<<"a = "<<a<<endl;
			ans[i] = -1;
		}
		else{
			set<int> :: iterator it;
			it = lower_bound(st.begin(), st.end(), a);
			if(it == st.end()){
			    cout<<"a = "<<a<<endl;
				ans[i] = -1;
			}
			else{
				ans[i] = *it;
			}
		}
		st.insert(a);
	}
	for(int i=0; i<n; i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}