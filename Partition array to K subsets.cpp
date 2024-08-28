//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */
class Solution{
  public:
    bool solve(int ind, int currSum, int targetSum, int k, int a[], int n, vector<bool>& visited){
        if(k == 1) return true;
        if(currSum == targetSum) return solve(0, 0, targetSum,k-1, a, n, visited);
        if(currSum >  targetSum) return false;
        for(int i = ind; i < n; i++){
            if(!visited[i]){
                visited[i] = true;
                if(solve(ind + 1, currSum + a[i], targetSum, k, a, n, visited)) return true;
                visited[i] = false;
            }
        }
        return false;
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         int sum = 0;
         for(int i = 0; i < n; i++) sum += a[i];
         if(sum % k) return false;
         sum /= k;
         vector<bool> visited(n, false);
         return solve(0, 0, sum, k, a, n, visited);
         
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends
