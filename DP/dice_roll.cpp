//dice roll
class Solution {
public:
    vector <vector <int> > dp;
    int mod = 1e9+7;
    int func(int d,int f,int target,int csum,int times)
    {
        if(csum == target && times == d)
            return 1;
        if(csum + f*(d-times) < target) return 0;
        if(csum > target || times > d) return 0;
        if(dp[times][csum] != -1) return dp[times][csum];
        int result = 0;
        for(int i=1;i<=f;i++)
        {
            result  = (result + func(d,f,target,csum+i,times+1)%mod) % mod;
        }
        return dp[times][csum] = result;
    }
    int numRollsToTarget(int d, int f, int target) {
        dp.clear();
        dp.resize(d+1,vector <int> (target+1,-1));
        return func(d,f,target,0,0);
    }
};