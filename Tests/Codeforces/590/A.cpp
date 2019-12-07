#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        vector <int> A(n);
        int sum =0 ;
        for(int i=0; i<n; i++){
            cin>>A[i];
            sum += A[i];
        }
        int result = sum%n == 0 ? sum/n : sum/n+1;
        cout<<result<<endl;
    }
    return 0;
}