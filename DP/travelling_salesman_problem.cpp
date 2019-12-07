#include <bits/stdc++.h>
using namespace std;
vector <vector <int> > dp;
vector <vector <int> > input;
int n, complete;
int func(int last_state,int mask){
   // cout<<last_state<<" "<<mask<<endl;
    if(mask == complete)
        return input[last_state][0];
    if(dp[last_state][mask] != -1)
        return dp[last_state][mask];
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        if((mask & (1<<i)) == 0){
            ans = min(ans, input[last_state][i] + func(i, mask | (1<<i)) );
        }
    }
    return dp[last_state][mask] = ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int power = pow(2,n);
        input.clear();
        input.resize(n,vector <int> (n));
        dp.clear();
        dp.resize(n,vector <int> (power,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>input[i][j];
            }
        }
        complete = power-1;
        int mask = 1;
        cout<<func(0,mask)<<endl;
    }
    return 0;
}