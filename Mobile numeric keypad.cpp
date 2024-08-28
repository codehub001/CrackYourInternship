class Solution {
  public:
    bool isvalid(int i, int j) {
        if ((i == 3 && j == 0) || (i == 3 && j == 2)) return false;
        if (i < 0 || i >= 4 || j < 0 || j >= 3) return false;
        return true;
    }
    
    long long help(vector<vector<char>> &grid, int i, int j, int n, vector<vector<vector<long long>>> &dp) {

        if (!isvalid(i, j)) return 0; 
        if (n == 1) return 1;
        
        if (dp[i][j][n] != -1) return dp[i][j][n];
        
        long long result = 0;
        
        if (isvalid(i, j)) {
            result += help(grid, i, j, n - 1, dp); // Stay at the current position
        }
        if (isvalid(i - 1, j)) {
            result += help(grid, i - 1, j, n - 1, dp); // Move up
        }
        if (isvalid(i + 1, j)) {
            result += help(grid, i + 1, j, n - 1, dp); // Move down
        }
        if (isvalid(i, j + 1)) {
            result += help(grid, i, j + 1, n - 1, dp); // Move right
        }
        if (isvalid(i, j - 1)) {
            result += help(grid, i, j - 1, n - 1, dp); // Move left
        }

        dp[i][j][n] = result;
        return result;
    }


    long long getCount(int n) {
        if (n <= 0) return 0;

        vector<vector<char>> grid = {
            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'},
            {'*', '0', '#'}
        };

        long long ans = 0;
        vector<vector<vector<long long>>> dp(4, vector<vector<long long>>(3, vector<long long>(n + 1, -1)));
        
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (isvalid(i, j)) {
                    ans += help(grid, i, j, n, dp);
                }
            }
        }
        
        return ans;
    }
};
