class Solution {
public:
    int solve(int k, int n, vector<vector<int>>& dp){
        if(n == 0 || n == 1 || k == 1) return n;
        if(dp[n][k] != -1) return dp[n][k];
        int ans=1000000,l=1,h=n,temp=0; 
        while(l <= h){
            int mid = (l + h)/2;
            int left = solve(k-1, mid-1, dp);
            int right = solve(k, n-mid, dp);
            temp = 1 + max(left, right);
            if(left < right) l = mid+1;
            else h = mid-1;
            ans = min(ans, temp);
        }
        return dp[n][k] = ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return solve(k, n, dp);
    }
};
