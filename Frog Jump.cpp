class Solution {
public:
    int dest;
    bool solve(unordered_map<int, int>& mp, int pos, int lj, vector<vector<int>>& dp){
        if(lj <= 0){
            return false;
        }
        if(pos == dest){
            return true;
        }
        if(!mp[pos]){
            return false;
        }
        if(dp[mp[pos]][lj] != -1){
            return dp[mp[pos]][lj];
        }
        return dp[mp[pos]][lj] = solve(mp, pos + lj, lj, dp) || solve(mp, pos + lj + 1, lj+1, dp) || solve(mp, pos + lj - 1, lj - 1, dp);
    }
    bool canCross(vector<int>& stones) {
        vector<vector<int>> dp(stones.size(), vector<int>(stones.size(), -1));
        unordered_map<int, int> mp;
        dest = stones[stones.size()-1];
        for(int i = 1; i < stones.size(); i++){
            mp[stones[i]] = i;
        }
        return solve(mp, stones[0]+1, 1, dp);
    }
};
