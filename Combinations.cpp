class Solution {
public:
    void solve(int n, int k, vector<vector<int>>& ans, vector<int>& temp){
        if(k == 0){
            ans.push_back(temp);
            return;
        }
        if(n == 0 || n < k){
            return;
        }
        temp.push_back(n);
        solve(n-1, k-1, ans, temp);
        temp.pop_back();
        solve(n-1, k, ans, temp);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(n, k, ans, temp);
        return ans;
    }
};
