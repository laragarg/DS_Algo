class Solution {
public:
    int n;
    vector<vector<vector<int> > >dp;
    int func(vector<vector<int> >&A, int ai, int aj, int bi){
        int bj = ai + aj - bi;
        if(ai == n-1 && bi == n-1 && aj == n-1 && bj == n-1){
            return A[ai][aj];
        }
        else if(ai >=n || bi >= n || aj >= n || bj >= n){
            return INT_MIN;
        }
        if(A[ai][aj] == -1 || A[bi][bj] == -1){
            return INT_MIN;
        }
        if(dp[ai][aj][bi] != -1){
            return dp[ai][aj][bi];
        }
        int a = A[ai][aj];
        int b = A[bi][bj];
        int res = 0;
        int t1 = func(A, ai+1, aj, bi+1);
        int t2 = func(A, ai+1, aj, bi);
        int t3 = func(A, ai, aj+1, bi+1);
        int t4 = func(A, ai, aj+1, bi);
        res = max(t1, max(t2, max(t3, t4)));
        if(res == INT_MIN){
            return dp[ai][aj][bi] = res;
        }
        if(ai != bi ){
            res += (a+b);
        }
        else{
            res += a;
        }
        return dp[ai][aj][bi] = res;
    }
    int cherryPickup(vector<vector<int>>& A) {
        n = A.size();     
        dp.clear();
        dp.resize(n, vector<vector<int>>(n, vector<int>(n, -1)));
        int ans = func(A, 0, 0, 0);
        return max(ans, 0);
        // return func(A, 0, 0, 0) == INT_MIN ? 0 : func(A,0,0,0);
    }
};