class Solution {
public:
    int solve(int n, int currPos, vector<vector<int>>& dp) {
        if (n == 0) {
            return 1;
        }
        int mod = 1000000007;
        if (dp[n][currPos] != -1) return dp[n][currPos];
        if (currPos == 1) {
            return dp[n][currPos] = (solve(n-1, 8, dp) % mod + solve(n-1, 6, dp) % mod) % mod;
        } else if (currPos == 2) {
            return dp[n][currPos] = (solve(n-1, 7, dp) % mod + solve(n-1, 9, dp) % mod) % mod;
        } else if (currPos == 3) {
            return dp[n][currPos] = (solve(n-1, 8, dp) % mod + solve(n-1, 4, dp) % mod) % mod;
        } else if (currPos == 4) {
            return dp[n][currPos] = ((solve(n-1, 3, dp) % mod + solve(n-1, 9, dp) % mod) % mod + solve(n-1, 0, dp) % mod) % mod;
        } else if (currPos == 5) {
            return 0;
        } else if (currPos == 6) {
            return dp[n][currPos] = ((solve(n-1, 1, dp) % mod + solve(n-1, 7, dp) % mod) % mod + solve(n-1, 0, dp) % mod) % mod;
        } else if (currPos == 7) {
            return dp[n][currPos] = (solve(n-1, 2, dp) % mod + solve(n-1, 6, dp) % mod) % mod;
        } else if (currPos == 8) {
            return dp[n][currPos] = (solve(n-1, 1, dp) % mod + solve(n-1, 3, dp) % mod) % mod;
        } else if (currPos == 9) {
            return dp[n][currPos] = (solve(n-1, 2, dp) % mod + solve(n-1, 4, dp) % mod) % mod;
        }
        return dp[n][currPos] = (solve(n-1, 4, dp) % mod + solve(n-1, 6, dp) % mod) % mod;
    }

    int knightDialer(int n) {
        int mod = 1000000007;
        int ans = 0;
        vector<vector<int>> dp(n+1, vector<int>(10, -1));
        for (int i = 0; i <= 9; i++) {
            ans = (ans + solve(n-1, i, dp) % mod) % mod;
        }
        return ans;
    }
};
