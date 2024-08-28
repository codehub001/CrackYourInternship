class Solution {
public:
    int solve(string& s, int i, string& t, int j, vector<vector<int>>& dp){
        if(j >= t.size()) return 1;
        if(i >= s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] != t[j]) return dp[i][j] = solve(s, i+1, t, j, dp);
        else return dp[i][j] = solve(s, i+1, t, j+1, dp) + solve(s, i+1, t, j, dp);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return solve(s, 0, t, 0, dp);
    }
};
