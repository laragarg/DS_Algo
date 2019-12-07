class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n));
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
        }
        //dp[i][j] will give us the lps we can get between i and j
        int gap, i, j;//gap is the length of current subsequence
        for(gap=1; gap<n; gap++){
            for(i=0, j=gap; j<n; i++, j++){
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};