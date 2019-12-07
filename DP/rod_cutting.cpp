#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//code for normal rod cutting problem
int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int> >dp(n+1, vector<int>(n+1));
        vector<int> A(n);//values vector
        for(int i=1; i<=n; i++){
            dp[i][0]=0;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i==1){
                    dp[i][j]=A[i-1]*j;
                }
                else if(i>j){
                    dp[i][j]=dp[i-1][j];
                }
                else if(i<=j){
                    dp[i][j] = max(dp[i-1][j], A[i-1] + dp[i][j-i]);
                }
            }
        }
        cout<<dp[n][n];
    }
    return 0;
}