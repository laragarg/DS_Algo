class Solution {
public:
    //Top down
    map<int, int> m;
    int ans;
    int func(vector<int> &nums, int i){ 
        int n = nums.size();
        if(i == 0){
            return 1;
        }
        if(m.find(i) != m.end()){
            return m[i];
        }
        m[i] = 1;
        for(int j=i-1; j>=0; j--){
            if(nums[j] < nums[i]){
                m[i] = max(m[i], 1 + func(nums, j));
            }
            ans = max(ans, m[i]);
        }
        
        return m[i];
    }
    int lengthOfLIS(vector<int>& nums) {
        m.clear();
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        ans = 1;
        for(int i = n-1; i>=0; i--){
            int temp = func(nums, i);    
        }
        return ans;
    }
};