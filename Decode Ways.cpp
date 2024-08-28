class Solution {
public:
    int solve(string& s, int i, vector<int>& dp){
        if(i >= s.length()){
            return 1;
        }
        if( s[i]== '0'){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int ans = solve(s, i+1, dp);
        if(i < s.length()-1 && (s[i] == '1' || s[i] == '2' && s[i+1] >= '0' && s[i+1] <= '6')){
            ans += solve(s, i+2, dp);
        }
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        vector<int> dp(s.length(), -1);
        return solve(s, 0, dp);
    }
};
