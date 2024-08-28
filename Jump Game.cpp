class Solution {
public:
    bool possible(vector<int>& nums, int s, int n, vector<int>& dp){
        if(s>=n){
            return true;
        }
        if(dp[s] != -1){
            return dp[s];
        }
        int jump = nums[s];
        for(int i = jump; i >= 1; i--){
            if(possible(nums, s+i, n,dp)){
                dp[s] = 1;
                return true;
            }
        }
        dp[s] = 0;
        return false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return possible(nums, 0, nums.size()-1, dp);
    }
};
