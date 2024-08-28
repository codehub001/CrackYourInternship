#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[50][50][50];
    int minCost(int i,int j,int piles,vector<int>&prefixsum,int &K){
        if( i == j && piles == 1)
            return 0;
        
        if(i == j)
            return INT_MAX/4;
        
        if(dp[i][j][piles]!=-1)
            return dp[i][j][piles];
        
        if(piles == 1){
            return dp[i][j][piles] = minCost(i,j,K,prefixsum,K) + (i==0 ? prefixsum[j] : prefixsum[j]-prefixsum[i-1]);
        } else {
            int cost = INT_MAX/4;
            for(int t=i;t<j;t++){
                cost = min(cost, minCost(i,t,1,prefixsum,K) + minCost(t+1,j,piles-1,prefixsum,K));                
            }
            return dp[i][j][piles] = cost;
        }
    }
    
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if((n-1)%(k-1)!=0) return -1;
        int sum = 0;
        vector<int>prefixsum;
        for(int i=0;i<stones.size();i++){
            sum+=stones[i];
            prefixsum.push_back(sum);
        }
        memset(dp,-1,sizeof(dp));
        return minCost(0,n-1,1,prefixsum,k);
    }
};
