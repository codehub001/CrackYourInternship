//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> key(V, INT_MAX);
        vector<bool> mst(V, false);
        
        
        key[0] = 0;
        for(int i = 0; i < V; i++){
            int miniKey = INT_MAX;
            int node;
            for(int j = 0; j < V; j++){
                if(!mst[j] && key[j] < miniKey){
                    miniKey = key[j];
                    node = j;
                }
            }
            mst[node] = true;
            for(auto& neigh:adj[node]){
                if(!mst[neigh[0]] && key[neigh[0]] > neigh[1]){
                    key[neigh[0]] = neigh[1];
                }
            }
        }
        int ans = 0;
        for(int i:key){
            ans += i;
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
