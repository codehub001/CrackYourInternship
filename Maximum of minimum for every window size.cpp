//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        vector<int> ans(n, 0);
        vector<int> leftMin(n);
        vector<int> rightMin(n);
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) leftMin[i] = -1;
            else leftMin[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(st.empty()) rightMin[i] = n;
            else rightMin[i] = st.top();
            st.push(i);
        }
        for(int i = 0; i < n; i++){
            int win = rightMin[i] - leftMin[i] - 2;
            ans[win] = max(ans[win], arr[i]);
        }
        for(int i = n-2; i >= 0; i--){
            ans[i] = max(ans[i], ans[i+1]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
