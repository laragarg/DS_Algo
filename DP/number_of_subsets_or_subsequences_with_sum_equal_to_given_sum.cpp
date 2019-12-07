#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<vector<int> >dp;
vector<int> A;
vector<vector<int> >ans;
void func(int i, int s, vector<int> temp){
    // cout<<"i = "<<i<<" s = "<<s<<endl;
    if(i == 0 && s != 0){
        temp.push_back(A[i]);
        ans.push_back(temp);
        return;
    }
    if(i == 0 && s == 0){
        ans.push_back(temp);
        return;
        // return 1;
    }
    if(dp[i-1][s]){
        func(i-1, s, temp);
    }
    if(s >= A[i] && dp[i-1][s-A[i]]){
        temp.push_back(A[i]);
        func(i-1, s - A[i], temp);
    }
    return;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        // int n;
        cin>>n;
        // vector<int>A(n);
        A.clear();
        A.resize(n);
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        int s;
        cin>>s;
        dp.clear();
        dp.resize(n, vector<int>(s+1, false));
        for(int i=0; i<n; i++){
            dp[i][0] = true;
        }
        for(int j=1; j<=s; j++){
            if(j == A[0]){
                dp[0][j] = true;
            }
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<=s; j++){
                if(A[i] > j){
                    dp[i][j] = dp[i-1][j];
                    continue;
                }
                else{
                    dp[i][j] = dp[i-1][j - A[i]] || dp[i-1][j];
                }
            }
        }
        if(!dp[n-1][s]){
            cout<<0<<endl;
            continue;
        }
        else{
            ans.clear();
            vector<int> temp;
            func(n-1, s, temp);
            // cout<<"out"<<endl;
            // for(int i=0; i<ans.size(); i++){
            //     for(int j=0; j<ans[i].size(); j++){
            //         cout<<ans[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
            cout<<ans.size()<<endl;
        }
    }
    return 0;
}