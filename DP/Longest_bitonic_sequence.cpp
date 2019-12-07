int n;
vector<int> lis;
vector<int> lds;
void inc(const vector<int> &A){
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(A[i] > A[j]){
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    return;
}
void dec(const vector<int> &A){//this is the longest increasing
                            //subsequence from end
    for(int i=n-2; i>=0; i--){
        for(int j=n-1; j>i; j--){
            if(A[i] > A[j]){
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }
}
int Solution::longestSubsequenceLength(const vector<int> &A) {
    n = A.size();
    if(n <= 2){
        return n;
    }
    lis.clear();
    lds.clear();
    lis.resize(n, 1);
    lds.resize(n, 1);
    int ans = INT_MIN;
    inc(A);
    dec(A);
    for(int i=0; i<n; i++){
        ans = max(ans, lis[i] + lds[i] - 1);// -1 because they were initialized
                                        //with 1 while declaring them
    }
    return ans;
}
