class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& informTime, int time, int& ans){
        ans = max(time, ans);
        time += informTime[node];
        for(auto& i:adj[node]){
            dfs(i, adj, informTime, time, ans);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            if(manager[i] == -1) continue;
            adj[manager[i]].push_back(i);
        }
        int ans = 0;
        dfs(headID, adj, informTime, 0, ans);
        return ans;
    }
};
