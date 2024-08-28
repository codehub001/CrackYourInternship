class Solution {
public:
    int solve(unordered_map<int, pair<int,int>>& mp, int m, int n, int i, int siz, vector<vector<vector<int>>>& dp){
        if(m < 0 || n < 0) return INT_MIN;
        if(i >= siz) return 0 ;
        if(dp[i][m][n] != -1) return dp[i][m][n];
        return dp[i][m][n] = max(solve(mp, m, n, i+1, siz, dp), 1 + solve(mp, m - mp[i].first, n - mp[i].second, i+1, siz, dp));
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        unordered_map<int, pair<int,int>> mp;
        for(int i = 0; i < strs.size(); i++){
            int ones = 0;
            for(int j = 0; j < strs[i].size(); j++){
                if(strs[i][j] == '1') ones++;
            }
            mp[i] = make_pair(strs[i].size()-ones, ones);
        }
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m+1, vector<int> (n+1, -1)));
        return solve(mp, m, n, 0, strs.size(), dp);
    }
};
