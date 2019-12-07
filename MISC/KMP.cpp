//https://www.youtube.com/watch?v=D6dCOa_gMoY&t=101s
class Solution {
public:
    vector<int> func(string &t){
        int m = t.size();
        vector<int> lps(m);//stores the length of longest prefix which is also a suffix of substring(0, r)
        lps[0] = 0;//value for first character is always zero
        int len = 0;// 
        int r = 1;
        while(r < m && len < m){
            if(t[r] == t[len]){
                lps[r] = len + 1;
                r++;
                len++;
            }
            else{
                if(len != 0){
                    len = lps[len-1];
                }
                else{
                    lps[r] = 0;
                    r++;
                }
            }
        }
        return lps; 
    }
    int strStr(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m == 0){
            return 0;
        }
        if(n < m){
            return -1;
        }
        if(n == m){
            if(s == t){
                return 0;
            }
            else{
                return -1;
            }
        }
        int i = 0;//for s
        int j = 0;//for t
        vector<int> lps = func(t);//tells us the count of characters to be skipped
        //lps[i] gives the the length of longest prefix which is also a suffix of substring till i
        while(i < n && j < m){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            if(j == m){
                return (i - j);
                j = lps[j-1];
            }

            // mismatch after j matches
            else if(i < n && s[i] != t[j]){
                // Do not match lps[0..lps[i-1]] characters, 
            // they will match anyway, so skip lps[j-1] number of characters
            //i.e. rather than going back to j = 0, we can start matching from j = lps[i-1]
                if(j != 0){
                    j = lps[j-1];//KMP omptimization(1)
                }
                else{//we can't go backwards any further in target string
                    //so just move forward to next character in source string
                    i = i + 1;//KMP omptimization(2)
                }
            }
        }
        return -1;
    }
};


//Brute force
/*
int strStr(string s, string t) {
    int n = s.size();
    int m = t.size();
    if(m == 0){
        return 0;
    }
    if(n < m){
        return -1;
    }
    if(n == m){
        if(s == t){
            return 0;
        }
        else{
            return -1;
        }
    }
    for(int i=0; i<n; i++){
        if(s[i] != t[0]){
            continue;
        }
        else{
            int x = i;
            int j = 0;
            while(x<n && j<m && s[x] == t[j]){
                x++;
                j++;
            }
            if(j == m){
                return i;
            }
        }
    }
    return -1;
}
*/