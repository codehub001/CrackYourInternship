class Solution {
public:
    int findNext(unordered_map<int, vector<int>>& adj, int curr, int prev){
        if(adj[curr].size() == 1){
            return adj[curr][0];
        }
        // cout<<prev<<" "<<adj[prev][0]<<" "<<adj[prev][1]<<endl;
        if(adj[curr][0] == prev) return adj[curr][1];
        return adj[curr][0];
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        for(auto& i : adjacentPairs){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int start;
        for(auto& i : adj){
            if(i.second.size() == 1){
                start = i.first;
                break;
            }
        }
        vector<int> ans(adjacentPairs.size()+1);
        ans[0] = start;
        int prev = 0;
        for(int i = 1; i < ans.size(); i++){
            ans[i] = findNext(adj, ans[i-1], prev);
            prev = ans[i-1];
        }
        return ans;

    }
};
