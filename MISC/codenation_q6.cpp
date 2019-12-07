#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define int long long
int n;


signed main() {
    string s; cin>>s;
    n = s.size();
    vector<int> d1(n+10,0);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    vector<int> dp1(n+10,0);
    vector<int> dp2(n+10,0);
    for(int i=0;i<n;i++){
        int ind = d1[i] + i - 1;
        int v = d1[i] * 2 -1;
        while(dp1[ind] <= v){
            dp1[ind] = v;
            ind--;
            v-=2;
        }
        ind = -d1[i] + i + 1;
        // cout<<ind<<" "<<i<<endl;
        v = d1[i] * 2 - 1;
        while(dp2[ind] <= v){
            dp2[ind] = v;
            ind++;
            v-=2;
        }
    }
    int ans = 0;
    for(int i=0;i<n-1;i++){
        ans = max(ans, dp1[i]*dp2[i+1]);
    }
    // for(int i=0;i<n;i++){
    //     cout<<dp2[i]<<" ";
    // }
    cout<<ans;
    return 0;
}