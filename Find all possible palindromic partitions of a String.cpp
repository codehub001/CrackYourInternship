//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void solve(int index,vector<vector<string>>& ans, vector<string>& temp, string S) {
        if(index==S.size()) {
            ans.push_back(temp);
            return;
        }
        
        for(int i=index;i<S.size();i++) {
            if(isPossible(S,index,i)) {
                temp.push_back(S.substr(index, i-index+1));
                solve(i+1,ans,temp,S);
                temp.pop_back();
            }
        }
    }
    
    bool isPossible(string s, int start, int end) {
        while(start<end) {
            if(s[start]!=s[end]) return false;
            start++,end--;
        }
        return true;
    }
    vector<vector<string>> allPalindromicPerms(string S) {
       vector<vector<string>>ans;
       vector<string>temp;
       solve(0,ans,temp,S);
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
