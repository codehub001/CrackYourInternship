class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        char prev_clr = colors[0];
        int prev_cost = neededTime[0];
        for(int i = 1; i < colors.size(); i++){
            if(colors[i] == prev_clr){
                ans += min(prev_cost, neededTime[i]);
                prev_cost = max(prev_cost, neededTime[i]);
            }
            else{
                prev_clr = colors[i];
                prev_cost = neededTime[i];
            }
        }
        return ans;
    }
};
