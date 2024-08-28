class Solution {
public:
    int solve(vector<vector<char>>& matrix, int i, int j, int& maxi, vector<vector<int>>& dp){
        if(i >= matrix.size() || j >= matrix[0].size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = solve(matrix, i, j+1, maxi, dp);
        int bottom = solve(matrix, i+1, j, maxi, dp);
        int diagonal = solve(matrix, i+1, j+1, maxi, dp);

        if(matrix[i][j] == '1'){
            int ans = 1 + min(right, min(bottom, diagonal));
            maxi = max(maxi, ans);
            dp[i][j] = ans;
            return ans;
        }
        else{
            return 0;
        }
    }

    int solve2(vector<vector<char>>& matrix){
        vector<vector<int>> dp(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        int maxi = 0;

        for(int i = matrix.size() - 1; i >= 0; i--){
            for(int j = matrix[0].size() - 1; j >= 0; j--){
                int right = dp[i][j+1];
                int bottom = dp[i+1][j];
                int diagonal = dp[i+1][j+1];

                if(matrix[i][j] == '1'){
                    int ans = 1 + min(right, min(bottom, diagonal));
                    maxi = max(maxi, ans);
                    dp[i][j] = ans;
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return maxi*maxi;
    }

    int solve3(vector<vector<char>>& matrix){
        vector<int> curr(matrix[0].size()+1, 0);
        vector<int> next(matrix[0].size()+1, 0);

        int maxi = 0;

        for(int i = matrix.size() - 1; i >= 0; i--){
            for(int j = matrix[0].size() - 1; j >= 0; j--){
                int right = curr[j+1];
                int bottom = next[j];
                int diagonal = next[j+1];

                if(matrix[i][j] == '1'){
                    int ans = 1 + min(right, min(bottom, diagonal));
                    maxi = max(maxi, ans);
                    curr[j] = ans;
                }
                else{
                    curr[j] = 0;
                }
            }
            next = curr; 
        }
        return maxi*maxi;
    }

    int maximalSquare(vector<vector<char>>& matrix){
        // int maxi = 0;
        // vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        // solve(matrix, 0, 0, maxi, dp);
        // return maxi*maxi;
        return solve3(matrix);
    }
};
