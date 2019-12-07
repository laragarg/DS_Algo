class Solution {
public:
    vector<vector<int> >memo;
    bool func(string &s, string &p, int i, int j){
        int n = s.size();
        int m = p.size();
        if(i >= n && j >= m){
            return true;
        }
        else if(j >= m){
            return false;
        }
        else if(i >= n){
            if(p[j] != '*'){
                return false;
            }
            return func(s, p, i, j+1);
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        bool res = false;
        if(p[j] == '*'){
            res = func(s, p, i+1, j) | func(s, p, i, j+1);
        }
        else if(p[j] == '?'){
            res = func(s, p, i+1, j+1);
        }
        else if(s[i] == p[j]){
            res = func(s, p, i+1, j+1);
        }
        return memo[i][j] = res;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        memo.clear();
        if(n == 0){
            if(m == 0){
                return true;
            }
            else if(m == 1 && p[0] == '*'){
                return true;
            }
            return false;
        }
        memo.resize(n, vector<int>(m, -1));
        return func(s, p, 0, 0);
    }
};