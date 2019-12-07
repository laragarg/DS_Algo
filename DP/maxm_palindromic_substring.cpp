class Solution {
public:
    string longestPalindrome(string A) {
        int n = A.size();
        vector<vector<bool> >dp(n, vector<bool>(n, false));
    
        int maxm = 1;
        for(int i=0; i<n; i++){
            dp[i][i] = 1;//string of length 1 is always palindrome
        }
        
        int start = 0;
        //for length = 2 or gap = 1;
        for(int i=0; i<n-1; i++){
            if(A[i] == A[i+1]){
                dp[i][i+1] = true;
                start = i;
                maxm = 2;
            }
        }
        
        //for length = 2 or gap = 1
        for(int gap=2; gap<n; gap++){
            for(int i=0, int j=gap; i<n, j<n; i++, j++){
                if(A[i] == A[j] && dp[i+1][j-1] == true){
                    dp[i][j]=true;
                    maxm = max(maxm, j-i+1);
                    if(maxm == j-i+1){
                        start = i;
                    }
                }
            }
        }
        string ans;
        ans = A.substr(start, maxm);
        return ans;
    }
};