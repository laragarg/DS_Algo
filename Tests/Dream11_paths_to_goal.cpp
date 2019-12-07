#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

int dp[1001][2501][2];

int solveUtil( string moves, int n, int start, int end, int idx, bool flag ){

if( start < 0 || start >n ){
    return 0;
}

if( start == end && idx == moves.size() ){
    return 1;
}

if( idx >= moves.size() ){
    return 0;
}

if( dp[idx][start][flag] != -1 ){
    return dp[idx][start][flag];
}

int ans = 0;
if( (moves[idx] == 'l' && flag) || (moves[idx] == 'r' && !flag) ){

    int change = moves[idx] == 'l' ? -1 : 1;

    ans = (solveUtil( moves, n, start+change, end, idx+1, flag )%M +
          solveUtil( moves, n, start+change, end, idx+1, !flag )%M)%M;
}else{
    ans = solveUtil( moves, n, start, end, idx+1, flag );
}
return dp[idx][start][flag] = ans;
}

int solve( string moves, int n, int start, int end ){
memset(dp,-1,sizeof(dp));

return solveUtil( moves, n, start, end, 0, false ) + solveUtil( moves, n, start, end, 0, true );
}