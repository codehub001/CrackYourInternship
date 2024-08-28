class Solution {
public:
    void dfsSolve(unordered_map<string, unordered_map<string, double>> &adj, unordered_set<string>& visited, string from, string& to, double& ans, double temp){
        if(ans != -1) return;
        visited.insert(from);
        if(from == to){
            ans = temp;
            return;
        }
        for(auto& i : adj[from]){
            if(visited.find(i.first) == visited.end()){
                dfsSolve(adj, visited, i.first, to, ans, temp*i.second);
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> adj;
        vector<double> ans(queries.size());
        for(int i = 0; i < equations.size(); i++){
            adj[equations[i][0]][equations[i][1]] = values[i];
            adj[equations[i][1]][equations[i][0]] = 1.0/values[i];
        }
        for(int i = 0; i < queries.size(); i++){
            if(adj.find(queries[i][0]) == adj.end() || adj.find(queries[i][1]) == adj.end()) ans[i] = -1;
            else{
                unordered_set<string> visited;
                double temp_ans = -1, temp = 1;
                dfsSolve(adj, visited, queries[i][0], queries[i][1], temp_ans, temp);
                ans[i] = temp_ans;
            }
        }
        return ans;

    }
};
