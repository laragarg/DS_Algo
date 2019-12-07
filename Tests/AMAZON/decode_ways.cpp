class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0 || s[0] == '0'){
            return 0;
        }
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            char x = s[i-1];
            char y = s[i-2];
            if(x != '0'){ //considering the number formted by current digit only
                dp[i] = dp[i-1];
            }
            if(y == '1' ||(y == '2' && x <= '6')){//considering the number 
                                    //formed with previous digit as well
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};