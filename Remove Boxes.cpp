class Solution {
    int dp[101][101][101];
public:
    int solve(int s, int e, int extra, vector<pair<int,int>>& buckets){
        if(s > e) return 0;
        if(dp[s][e][extra] != -1) return dp[s][e][extra];
        int ans = (buckets[s].second + extra) * (buckets[s].second + extra) +  solve(s+1, e, 0, buckets);
        for(int i = s+1; i <= e; i++){
            if(buckets[s].first == buckets[i].first){
                ans = max(ans, solve(s+1, i-1, 0, buckets) + solve(i, e, extra + buckets[s].second, buckets));
            }
        }
        return dp[s][e][extra] = ans;
    }
    int removeBoxes(vector<int>& boxes) {
        vector<pair<int,int>> buckets;
        for(int i = 0; i < boxes.size(); i++){
            int temp = i;
            while(i+1 < boxes.size() && boxes[i] == boxes[i+1]) i++;
            buckets.push_back(make_pair(boxes[temp], i-temp+1));
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, buckets.size()-1, 0, buckets);
    }
};
