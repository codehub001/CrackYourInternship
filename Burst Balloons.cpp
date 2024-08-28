class Solution {
    int dp[301][301];
public:
    int solve(vector<int>& nums, int i, int j){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == j){
            int ans = nums[i]*nums[i-1]*nums[i+1];
            return dp[i][j] = ans;
        }
        int ans = 0;
        for(int k = i; k <= j; k++){
            ans = max(ans, nums[k]*nums[j+1]*nums[i-1] + solve(nums, i, k-1) + solve(nums, k+1, j));
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& tnums) {
        memset(dp, -1, sizeof(dp));
        vector<int> nums = {1};
        for(auto& i : tnums) nums.push_back(i);
        nums.push_back(1);
        return solve(nums, 1, nums.size() - 2);
    }
};
