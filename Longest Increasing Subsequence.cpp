class Solution {
public:
    int solve(int n, vector<int>& nums, int i, int min, vector<vector<int>>& dp){
        if(i >= n){
            return 0;
        }
        
        if(dp[i][min+1] != -1){
            return dp[i][min+1];
        }

        if(min != -1 && nums[i] <= nums[min]){
            return dp[i][min+1] = solve(n, nums, i+1, min, dp);
        }
        
        int include = 1 + solve(n, nums, i+1, i, dp);
        int exclude = solve(n, nums, i+1, min, dp);
        
        return dp[i][min+1] = max(include, exclude);
    }

    int solve2(vector<int>& nums){
        vector<vector<int>> dp(nums.size()+1, vector<int> (nums.size() + 1, 0));

        for(int i = nums.size()-1; i >= 0; i--){
            for(int min = i-1; min >= -1; min--){
                int include = 0;
                if(min != -1 || nums[i] > nums[min]){
                    include = 1 + dp[i+1][i+1];
                }
                
                int exclude = dp[i+1][min+1];
                
                dp[i][min+1] = max(include, exclude);                 
            }
        }
        return dp[0][0];
    }

    int solveOptimal(vector<int>& nums){
        vector<int> ans;
        if(nums.size() == 0){
            return 0;
        }
        ans.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i]; 
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int>> dp(n, vector<int> (n+1, -1));
        // return solve(n, nums, 0, -1, dp);
        // return solve2(nums);
        return solveOptimal(nums);
    }
};
