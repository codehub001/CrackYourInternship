class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        if(i == grid.size()-1 && j == grid[0].size()-1){
            return grid[i][j];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = INT_MAX;
        int down = INT_MAX;

        if(i < grid.size()-1){
            right = solve(grid, i+1, j, dp);
        }
        if(j < grid[0].size()-1){
            down = solve(grid, i, j+1, dp);
        }
        return dp[i][j] = grid[i][j] + min(right, down);
    }

    int solveTab(vector<vector<int>>& grid){
        vector<int> next(grid[0].size());
        next[grid[0].size()-1] = grid[grid.size()-1][grid[0].size()-1];
        vector<int> curr = next;
        for(int i = grid.size()-1; i >= 0; i--){
            for(int j = grid[0].size()-1; j >= 0; j--){
                if(i == grid.size()-1 && j == grid[0].size()-1){
                    continue;
                }
                int right = INT_MAX;
                int down = INT_MAX;
                if(i < grid.size()-1){
                    right = next[j];
                }
                if(j < grid[0].size()-1){
                    down = curr[j+1];
                }
                curr[j] = grid[i][j] + min(right, down);        
            }
            next = curr;
        }
        return curr[0];
    }
    int minPathSum(vector<vector<int>>& grid) {
        return solveTab(grid);
        // vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        // return solve(grid, 0, 0, dp);
    }
};
