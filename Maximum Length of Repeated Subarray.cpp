class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j, int flag, vector<vector<vector<int>>>& dp){
        if(i >= nums1.size() || j >= nums2.size()) return 0;
        int ans = 0;
        if(dp[i][j][flag] != -1) return dp[i][j][flag];
        if(flag && nums1[i] != nums2[j]) return 0;
        else if(flag && nums1[i] == nums2[j]) return dp[i][j][flag] = 1 + solve(nums1, nums2, i+1, j+1, 1, dp);
        if(nums1[i] == nums2[j]) ans = 1 + solve(nums1, nums2, i+1, j+1, 1, dp);
        return dp[i][j][flag] = max(ans, max(solve(nums1, nums2, i+1, j, 0, dp), solve(nums1, nums2, i, j+1, 0, dp)));
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, i = 0;
        vector<vector<vector<int>>> dp(nums1.size(), vector<vector<int>> (nums2.size(), vector<int> (2, -1)));
        return solve(nums1, nums2, 0, 0, 0, dp);
    }
};
