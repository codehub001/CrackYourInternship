class Solution {
public:
    int solve(int n, int dp[]){
        if(n<=1){
            return 1;
        }
        if(n==2){
            return 2;
        } 
        if(dp[n-1]!=-1){
            return dp[n-1];
        } 
        dp[n-1] = solve(n-1, dp)+solve(n-2, dp);
        return dp[n-1];
    }
    int climbStairs(int n) {
        int dp[n];
        for(int i=0; i<n; i++){
            dp[i]=-1;
        }
        return solve(n, dp);
    }
};
