//Starting from 0
#include<bits/stdc++.h>
using namespace std;
// int ans;
int n;
int s;
vector<vector<int> >dp;
int func(int i, int curr_sum){
    if(curr_sum > s){
        return 0;
    }
	if(i >= n){
		if(curr_sum == s){
			return 1;
			// ans++;
		}
		return 0;
	}
	if(dp[i][curr_sum] != -1){
		return dp[i][curr_sum];
	}
	int res = 0;
	res += func(i+1, curr_sum + i) + func(i+1, curr_sum);
	return dp[i][curr_sum] = res;
}
int main(){
	cin>>n;
	s = n*(n+1)/2;
	if(s % 2 != 0){
	    cout<<"Not possible"<<endl;
	    return 0;
	}
	s = s/2;
	dp.clear();
	dp.resize(n+1, vector<int>(s + 1, -1));
	cout<<"ans = "<<func(1, 0);
// 	cout<<"ans = "<<ans<<endl;
	return 0;
}

//Starting from S
#include<bits/stdc++.h>
using namespace std;
// int ans;
int n;
int s;
vector<vector<int> >dp;
int func(int i, int sum){
	if(sum < 0) {
	    return 0;
	}
	if(i <= 0 ){
		if(sum == 0){
			return 1;
		}
		return 0;
	}
// 	cout<<"i = "<<i<<endl;
	if(dp[i][sum] != -1){
		return dp[i][sum];
	}
	dp[i][sum] = func(i-1, sum - i) +  func(i-1, sum);
	return dp[i][sum];
}
int main(){
	cin>>n;
	s = n*(n+1)/2;
	if(s%2==1) {
        cout<<"NO"<<endl;
	    return 0;
	}
	s = s/2;
	dp.clear();
	dp.resize(n+1, vector<int>(s + 1, -1));
	cout<<"ans = "<<func(n,s)/2<<endl;
	return 0;
}