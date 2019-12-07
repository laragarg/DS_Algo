//to get all the prime numbers upto A
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<bool> A(n+1, true);//initially mark all the numbers less than or equal to the number as prime
        //vector<int> ans;
        for(int i=2; i<=floor(sqrt(n)); i++){//i*i<=A to optimize the theorem
            if(A[i]==false){//if number has been found composite already, then continue
                continue;
            }
            for(int j=i*i; j<=n; j+=i){//now start from i^2 and mark all the multiples of i as composite
                A[j] = false;
            }
        }
        vector<int> ans;
        for(int i=2; i<=n; i++){
            if(A[i]){
                ans.push_back(i);    
            }
        }
        cout<<endl;
    }
    return 0;
}