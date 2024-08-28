class Solution {
public:
    bool dfscheck(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& isSafe){
        if(isSafe[node] != -1) return isSafe[node];
        for(auto& neighbour:graph[node]){
            if(visited[neighbour]) return isSafe[node] = false;
            visited[neighbour] = true;
            bool temp = dfscheck(neighbour, graph, visited, isSafe);
            visited[neighbour] = false;
            if(!temp) return isSafe[node] = false;
        }
        return isSafe[node] = true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> isSafe(graph.size(), -1);
        vector<int> ans;
        vector<bool> visited(graph.size(), 0);
        for(int i = 0; i < graph.size(); i++){
            visited[i] = true;
            if(dfscheck(i, graph, visited, isSafe)) ans.push_back(i);
            visited[i] = false;
        }
        return ans;
    }
};
