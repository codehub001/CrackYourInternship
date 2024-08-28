//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node, stack<int>& st, vector<bool>& visited, vector<vector<int>>& adj){
	    visited[node] = true;
	    for(auto& i:adj[node]){
	        if(!visited[i]) dfs(i, st, visited, adj);
	    }
	    st.push(node);
	}
	void solve(int node, vector<bool>& visited, vector<vector<int>>& adj){
	    visited[node] = true;
	    for(auto& i:adj[node]){
	        if(!visited[i]) solve(i, visited, adj);
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack<int> st;
        vector<vector<int>> transpose(V);
        vector<bool> visited(V, false);
        int ans = 0;
        
        for(int i = 0; i < V; i++){
            if(!visited[i]) dfs(i, st, visited, adj);
        }
        for(int i = 0; i < V; i++){
            visited[i] = false;
            for(int j = 0; j < adj[i].size(); j++){
                transpose[adj[i][j]].push_back(i);
            }
        }
        
        while(!st.empty()){
            int i = st.top();
            st.pop();
            if(visited[i]) continue;
            solve(i, visited, transpose);
            ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
