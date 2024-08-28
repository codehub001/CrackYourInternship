//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    int ans_area = 0;
    int ans_i, ans_j, ans_s, ans_e;
  public:
    bool subarraySum(vector<int>& nums, int& s, int& e) {
        int sum = 0;
        bool flag = false;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(mp[sum]){
                if(!flag || i - mp[sum] > e - s){
                    flag = true;
                    e = i;
                    s = mp[sum];
                }
            }
            else if(sum == 0){
                flag = true;
                e = i;
                s = 0;
            }
            else mp[sum] = i+1;
        }
        return flag;
    }
    vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
        for(int k = 0; k < a.size(); k++){
            vector<int> arr(a[0].size(), 0);
            for(int i = k; i < a.size(); i++){
                for(int j = 0; j < a[0].size(); j++){
                    arr[j] += a[i][j];
                }
                int s, e;
                bool pos = subarraySum(arr, s, e);
                int area = (i-k+1)*(e-s+1);
                if(pos && ans_area < area || pos && ans_area == area && ans_s > s || pos && ans_area == area && ans_s == s && ans_e > e){
                    ans_area = area;
                    ans_i = k;
                    ans_j = i;
                    ans_s = s;
                    ans_e = e;
                }
            }
        }
        // cout<<ans_j<<" "<<ans_i<<" "<<ans_s<<" "<<ans_e<<endl;
        // return a;
        vector<vector<int>> ans(ans_j-ans_i+1, vector<int>(ans_e-ans_s+1, 0));
        for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < ans[0].size(); j++){
                ans[i][j] = a[i+ans_i][j+ans_s];
            }
        }
        return ans;
        
      
    }
    
  
};


//{ Driver Code Starts.




int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if(ans.size() == 0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends
