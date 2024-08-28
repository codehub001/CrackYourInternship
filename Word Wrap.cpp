//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solve(vector<int>& nums, int& k, int i,  vector<int>& dp){
        if(i >= nums.size()-1){
            return 0;
        }
        int j = i;
        if(dp[i] != -1) return dp[i];
        int temp = 0;
        int ans = INT_MAX;
        while(i < nums.size() && temp + nums[i] <= k){
            temp += nums[i];
            ans = min(ans, (k - temp)*(k - temp) + solve(nums, k, i+1, dp));
            temp++;
            i++;
        }
        if(i >= nums.size()){
            return 0;
        }
        return dp[j] = ans;
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        vector<int> dp(nums.size(), -1);
        return solve(nums, k, 0, dp);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends
