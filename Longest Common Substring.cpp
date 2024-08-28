//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int t[1001][1001]; 
    int maxi = 0; 
    
    int helper(string &S1, string &S2, int n, int m){
        if(n == 0 || m == 0) return 0;
        
        if(t[n][m] != -1) return t[n][m];
        
        if(S1[n-1] == S2[m-1]){
            t[n][m] = 1 + helper(S1, S2, n-1, m-1);
            
            maxi = max(maxi, t[n][m]);
        }
        else{
            t[n][m] = 0;
        }
        
        helper(S1, S2, n-1, m); 
        helper(S1, S2, n, m-1);
        return t[n][m];
    }
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        memset(t, -1, sizeof(t));
        helper(S1, S2, n, m);
        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
