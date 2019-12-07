#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> A(n);
	for(int i=0; i<n; i++){
		cin>>A[i];
	}
	int k;
	cin>>k;
	int curr_len = 0;
	int ans = 0;
	int curr_sum = 0;
	for(int i=0; i<n; i++){
		if(curr_sum + A[i] <= k){
			curr_sum += A[i];
			curr_len++;
		}
		else if(curr_sum != 0){
			curr_sum -= A[i - curr_len] + A[i];
		}
		ans = max(ans, curr_len);
	}
	cout<"ans = "<<ans<<endl;
	return 0;
}