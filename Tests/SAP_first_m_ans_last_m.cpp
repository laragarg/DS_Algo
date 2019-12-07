#include<bits/stdc++.h>
using namespace std;
vector<int> A;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		A.clear();
		A.resize(n);
		priority_queue<int> pq1, pq2;
		for(int i=0; i<n; i++){
			cin>>A[i];
			if(i < m){
				pq1.push(A[i]);
			}
			else if(i >= n - m){
				pq2.push(A[i]);
			}
		}
		int m, x;
		cin>>m>>x;
		int l = m;
		int r = n-m-1;
		int ans = 0;
		for(int i=0; i<x; i++){
			if(pq1.top() >= pq2.top()){
				ans += pq1.top();
				if(l < r){
					pq1.pop();
				}
				l++;
			}
			else if(pq1.top() < pq2.top()){
				ans += pq2.top();
				pq2.pop();
				r--;
			}
			i++;
		}
	}	

	return 0;
}