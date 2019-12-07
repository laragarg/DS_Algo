//Reorder an array according to given indexes
#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}
int main(){
	int n;
	cin>>n;
	vector<pair<int, int> >A(n);
	for(int i=0; i<n; i++){
	   // cout<<"i = "<<i<<" ";
		cin>>A[i].first;
	}
	// vector<int>B(n);
	for(int i=0; i<n; i++){
		cin>>A[i].second;
	}
	sort(A.begin(), A.end(), comp);
	for(int i=0; i<n; i++){
		cout<<A[i].first<<" ";
	}
	return 0;
}