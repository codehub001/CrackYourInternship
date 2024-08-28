class Solution {
public:
    int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp){
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(i > 0 && matrix[i-1][j] > matrix[i][j]) ans = max(ans, 1 + solve(matrix, i-1, j, dp));
        if(i < matrix.size() - 1 && matrix[i+1][j] > matrix[i][j]) ans = max(ans, 1 + solve(matrix, i+1, j, dp));
        if(j > 0 && matrix[i][j-1] > matrix[i][j]) ans = max(ans, 1 + solve(matrix, i, j-1, dp));
        if(j < matrix[0].size() - 1 && matrix[i][j+1] > matrix[i][j]) ans = max(ans, 1 + solve(matrix, i, j+1, dp));
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(),-1));
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                ans = max(ans, solve(matrix, i, j, dp));
            }
        }
        return ans+1;
    }
};
