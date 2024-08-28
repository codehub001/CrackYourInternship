//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        vector<int> parent(V,  -1);
        queue<int> q;
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                q.push(i);
                while(!q.empty()){
                int n = q.size();
                for(int i = 0; i < n; i++){
                    int node = q.front();
                    q.pop();
                    visited[node] = true;
                    for(auto& neighbour:adj[node]){
                        if(!visited[neighbour]){
                            parent[neighbour] = node;
                            q.push(neighbour);
                        }
                        else if(parent[node] != neighbour) return true;
                    }
                }
            }
            }
            
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
