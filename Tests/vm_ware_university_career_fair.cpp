#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	vector<int> dep(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	for(int i=0; i<n; i++){
		cin>>dep[i];
	}
	
	vector<pair<int, int> >A(n);
	for(int i=0; i<n; i++){
		A[i].first = arr[i] + dep[i];
		A[i].second = arr[i];
	}
	sort(A.begin(), A.end());
	int ans = 1;
	int start = A[0].second;
	int end = A[0].first;
	for(int i=1; i<n; i++){
		if(A[i].second >= end){
			ans++;
			end = A[i].first;
		}
	}
	cout<<"ans = "<<ans<<endl;
	return 0;
}