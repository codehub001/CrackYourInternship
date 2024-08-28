class Solution {
public:
    unordered_map<int,int> mp;
    int solve(vector<int>& nums, int i, vector<int>& dp){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int j = mp[nums[i]];
        int count = j-i+1;
        int way1 = solve(nums, j+1, dp);
        if(mp[nums[i]+1]) j = mp[nums[i]+1];
        int way2 = count*nums[i] + solve(nums, j+1, dp);
        return dp[i] = max(way1, way2);
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) mp[nums[i]] = i;
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};
