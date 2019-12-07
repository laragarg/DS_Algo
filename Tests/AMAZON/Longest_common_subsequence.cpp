class Solution {
public:
    vector<vector<int> > m;
    int func(string &s1, string &s2, int i, int j){
        int n1 = s1.size();
        int n2 = s2.size();
        if(i >= n1 || j >= n2 || n1 == 0 || n2 == 0){
            return 0;
        }
        if(m[i][j] != -1){
            return m[i][j];
        }
        int temp = 0;
        if(s1[i] == s2[j]){
            temp = func(s1, s2, i + 1, j + 1) + 1;
        }
        
        else{
            int a, b;
            a = func(s1, s2, i + 1, j);
            b = func(s1, s2, i, j + 1); 
            temp = max(a, b);
        }
        return m[i][j] = temp;
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        m.resize(n1, vector<int>(n2, -1));
        return func(s1, s2, 0, 0);
    }
};

//Bottom Up
// class Solution {
// public:
//     int longestCommonSubsequence(string s1, string s2) {
//         int n = s1.size();
//         int m = s2.size();
//         vector<vector<int> >dp(n+1, vector<int>(m+1) );
//         for(int i=0; i<=n; i++){
//             dp[i][0] = 0;
//         }
//         for(int j=0; j<=m; j++){
//             dp[0][j] = 0;
//         }
//         for(int i=1; i<=n; i++){
//             for(int j=1; j<=m; j++){
//                 if(s1[i-1] == s2[j-1]){
//                     dp[i][j] = dp[i-1][j-1] + 1;
//                 }
//                 else{
//                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//                 }
//             }
//         }
//         return dp[n][m];
//     }
// };