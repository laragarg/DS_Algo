//Maximum subarray size, such that all subarrays of that size have sum less than k

#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> A;
    int n = A.size();
    vector<int> pref_sum;//sum till ith index excluding ith index
    pref_sum.push_back(0);
    for(int i=1; i<=n; i++){
        pref_sum.push_back(A[i - 1] + pref_sum[i - 1]);   
    }
    int k;//subarray size
    int lo = 1;//lowest subarray size
    int hi = n;//largest subarray size
    while(lo<hi){
        int mid = lo + (hi-lo)/2;
        int i = mid;
        int f = 0;
        for(i; i<=n; i++){// checking for all subarrays of size mid
            if(pref_sum[i] - pref_sum[i - mid]>k){
                f = 1;
                break;
            }
        }
        if(f == 1){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;//if loop didn't break, i.e. condition was satisfied for size = mid, 
                        //then check for sizes greater than mid
            ans= mid;
        }

    }
    return ans;
}