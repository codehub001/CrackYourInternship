//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    int nodes, colors;
    vector<int> color;
    bool isPos(bool graph[101][101], int curr, int col){
        for(int i = 0; i < curr; i++){
            if(graph[curr][i] && color[i] == col) return false;
        }
        return true;
    }
    bool solve(bool graph[101][101], int curr){
        if(curr >= nodes) return true;
        for(int i = 1; i <= colors; i++){
            if(isPos(graph, curr, i)){
                color[curr] = i;
                if(solve(graph, curr+1)) return true;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        nodes = n;
        colors = m;
        color.resize(n, 0);
        return solve(graph, 0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
