//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void minimumCashFlow(vector<int> &amount,vector<vector<int>> &transaction)
    {
        int mxCred = max_element(amount.begin(),amount.end()) - begin(amount);
        int mxDebt = min_element(amount.begin(),amount.end()) - begin(amount);
        if(amount[mxCred] == 0 && amount[mxDebt] == 0)
            return;
            
        int mn = min(amount[mxCred],-amount[mxDebt]);

        amount[mxCred] -= mn;
        amount[mxDebt] += mn;
        transaction[mxDebt][mxCred] = mn;
        minimumCashFlow(amount,transaction);
    }

    vector<vector<int>> minCashFlow(vector<vector<int>> &transaction, int n)
    {
        // code here
        vector<int> amount(n,0);
        for(int p = 0;p < n;p++)
        {
            for(int i = 0;i < n;i++)
            {
                amount[p] += (transaction[i][p] - transaction[p][i]);
            }
        }
        vector<vector<int>> ans(n,vector<int>(n,0));
        minimumCashFlow(amount,ans);
        return ans;
    }
};


//{ Driver Code Starts.

vector<int> balance(vector<vector<int>>& v, int n) {
    vector<int> bal(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bal[i] -= v[i][j];
            bal[j] += v[i][j];
        }
    }
    return bal;
}

bool isValid(vector<vector<int>>& g, vector<vector<int>>& r, int n) {
    return balance(g, n) == balance(r, n);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> g[i][j];
        }
        Solution obj;
        vector<vector<int>> r = obj.minCashFlow(g, n);
        if (isValid(g, r, n) == false) {
            cout << "-1\n";
            continue;
        }
        int flow = 0;
        for (auto j : r) {
            for (auto i : j) {
                if (i > 0)
                    flow++;
            }
        }
        cout << flow << "\n";
    }
    return 0;
}
// } Driver Code Ends
