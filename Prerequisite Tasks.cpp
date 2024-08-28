//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool solve(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& dfsCall){
        dfsCall[node] = true;
        visited[node] = true;
        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                if(solve(neighbour, adj, visited, dfsCall)){
                   return true;
               } 
            }
            else if(dfsCall[neighbour]){
                return true;
            }
        }
        dfsCall[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>>& adj) {
        // code here
        vector<bool> visited(V, false);
        vector<bool> dfsCall(V, false);
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
               if(solve(i, adj, visited, dfsCall)){
                   return true;
               } 
            }
        }
        return false;
    }
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<vector<int>> adj(N);
	    for(auto& i: prerequisites){
	        adj[i.second].push_back(i.first);
 	    }
 	    return !isCyclic(N, adj);
 	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends
