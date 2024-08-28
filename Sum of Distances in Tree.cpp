class Solution {
private:
    vector<vector<int>> adj;
    vector<int> ans, count;
    void dfsParSolve(int node, int parent = -1){
        for(auto& neighbour:adj[node]){
            if(neighbour == parent) continue;
            dfsParSolve(neighbour, node);
            count[node] += count[neighbour];
            ans[node] += ans[neighbour] + count[neighbour];
        }
    }
    void dfsAllSolve(int node, int parent = -1){
        for(auto& neighbour:adj[node]){
            if(neighbour == parent) continue;
            ans[neighbour] = ans[node] - count[neighbour] + count.size() - count[neighbour];
            dfsAllSolve(neighbour, node);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        ans.resize(n, 0);
        count.resize(n, 1);
        for(auto& edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfsParSolve(0);
        dfsAllSolve(0);
        return ans;
    }
};
