class Solution {
public:
    // void solve(int i, int j, int& ans, int m, int n){
    //     if(i > m || j > n){
    //         return;
    //     }
    //     if(i == m && j == n){
    //         ans++;
    //         return;
    //     }
    //     solve(i+1, j, ans, m, n);
    //     solve(i, j+1, ans, m, n);
    // }

    // int uniquePaths(int m, int n) {
    //     int ans=0;
    //     solve(0, 0, ans, m-1, n-1);
    //     return ans;
    // }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            dp[0][j] = 1;
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};
