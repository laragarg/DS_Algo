class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        string ans;
        if(n < m){
            return ans;
        }
        map<char, int> ms;
        map<char, int> mt;
        for(int i=0; i<m; i++){
            mt[t[i]]++;
        }
        int temp = 0;
        int start = 0;
        int count = 0;
        int windowmin = INT_MAX;
        for(int i=0; i<n; i++){
            char x = s[i];
            ms[x]++;
            if(ms[x] <= mt[x]){//if current character is present in target string
                count++;
            }
            //if all the charcters have been matched
            if(count == m){
                char y = s[temp];
                //minimize the window by removing redundant occurences
                while(ms[y] > mt[y]){
                    ms[y]--;
                    temp++;
                    y = s[temp];
                }
                int curr = i - temp + 1;
                windowmin = min(windowmin, curr);
                if(windowmin == curr){
                    start = temp;
                }
            }
        }
        //if now window found
        if(windowmin == INT_MAX){
            return ans;
        }
        ans = s.substr(start, windowmin);
        return ans;
    }
};



//Minimum window substring containing all the characters of itself

#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        int n = s.size();
        vector<int> ms(26, 0);
        for(int i=0; i<n; i++){
            char x = s[i];
            ms[x - 'a']++;
        }
        string t;
        vector<int> mt(26, 0);
        for(int i=0; i<26; i++){
            if(ms[i] != 0){
                t.push_back('a' + i);
                mt[i]++;
            }
            // t.push_back(it->firs);
        }
        int m = t.size();
        ms.clear();
        ms.resize(26, 0);
        int count = 0;
        int ans = INT_MAX;
        int temp = 0;
        for(int i=0; i<n; i++){
            char x = s[i];
            ms[x - 'a']++;
            if(mt[x - 'a'] >= ms[x - 'a']){
                count++;
            }
            if(count == m){
                char y = s[temp];
                while(ms[y - 'a'] > mt[y - 'a']){
                    ms[y - 'a']--;
                    // if(ms[y - 'a'] == 0){
                    //     ms.erase(x);
                    // }
                    temp++;
                    y = s[temp];
                }
                int curr_window = i - temp + 1;
                ans = min(ans, curr_window);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}