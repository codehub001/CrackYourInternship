class Solution {
public:
    int solve(int index, int buy, vector<int>& prices, vector<vector<vector<int>>>& dp, int limit){
        if(index == prices.size() || limit == 0){
            return 0;
        }

        if(dp[index][buy][limit] != -1){
            return dp[index][buy][limit];
        }
        int profit = 0;
        if(buy){
            profit = max((-prices[index] + solve(index+1, 0, prices, dp, limit)), (0 + solve(index + 1, 1, prices, dp, limit)));
        } 
        else{
            profit = max((prices[index] + solve(index+1, 1, prices, dp, limit-1)), (0 + solve(index + 1, 0, prices, dp, limit)));
        }
        return dp[index][buy][limit] = profit;
    }

    int solveTab(vector<int>& prices){ 
        vector<vector<vector<int>>> dp (prices.size()+1, vector<vector<int>>(2, vector<int> (3, 0)));
        for(int index = prices.size()-1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){
                for(int limit = 1; limit <=2; limit++){
                    int profit = 0;
                    if(buy){
                        profit = max((-prices[index] + dp[index+1][0][limit]), (0 + dp[index+1][1][limit]));
                    } 
                    else{
                        profit = max((prices[index] + dp[index+1][1][limit-1]), (0 + dp[index+1][0][limit]));
                    }
                    dp[index][buy][limit] = profit;

                }
            }
        }
        return dp[0][1][2];
    }

    int solveSpace(int k, vector<int>& prices){
        vector<vector<int>> curr(2, vector<int>(k+1, 0));
        vector<vector<int>> next(2, vector<int>(k+1, 0));

        for(int index = prices.size()-1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){
                for(int limit = 1; limit <=k; limit++){
                    int profit = 0;
                    if(buy){
                        profit = max((-prices[index] + next[0][limit]), (0 + next[1][limit]));
                    } 
                    else{
                        profit = max((prices[index] + next[1][limit-1]), (0 + next[0][limit]));
                    }
                    curr[buy][limit] = profit;

                }
            }
            next = curr;
        }
        return curr[1][k];

    }
    int maxProfit(int k, vector<int>& prices) {
        // vector<vector<vector<int>>> dp (prices.size(), vector<vector<int>>(2, vector<int> (k+1, -1)));
        // return solve(0, 1, prices, dp,k);
    
        return solveSpace(k, prices);
    }
};
