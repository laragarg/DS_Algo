#include<bits/stdc++.h>
using namespace std;
int main(){
	// int n;
	// cin>>n;
	int m;
	cin>>m;
	vector<pair<int, int> >A(m);
	for(int i=0; i<m; i++){
		int in, val;
		cin>>in>>val;
		A[i].first = in;
		A[i].second = val;
	}
	int ans = 0;
	for(int i=0; i<m-1; i++){
		if((A[i + 1].first - A[i].first) == 1){
			continue;	
		}
		int curr_max;
		if(A[i].second < A[i+1].second){
		  //  cout<<"here"<<endl;
			int diff = A[i+1].second - A[i].second;
			int x = A[i].first + diff;
			curr_max = A[i+1].second + (A[i+1].first - x)/2;
		}
		else{
			int diff = A[i].second - A[i+1].second;
			int x = A[i+1].first - diff;
			curr_max = A[i].second + (x - A[i].first)/2;
		}
		cout<<"curr_max = "<<curr_max<<endl;
		ans = max(ans, curr_max);
	}
	cout<<"ans = "<<ans;
	return 0;
}