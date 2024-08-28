class Solution {
public:
    void solve(vector<vector<int>>& matrix, vector<int>& ans, int is, int js, int ie, int je){
        if(is > ie || js > je){
            return;
        }
        for(int i = js; i <= je; i++){
            ans.push_back(matrix[is][i]);
        }
        cout<<ans[ans.size()-1];
        for(int i = is+1; i <= ie; i++){
            ans.push_back(matrix[i][je]);
        }
        if(is == ie || js == je){
            return;
        }
        for(int i = je-1; i >= js; i--){
            ans.push_back(matrix[ie][i]);
        }
        cout<<ans[ans.size()-1];
        for(int i = ie-1; i > is; i--){
            ans.push_back(matrix[i][js]);
        }
        cout<<ans[ans.size()-1]<<endl;
        solve(matrix, ans, is+1, js+1, ie-1, je-1);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        solve(matrix, ans, 0, 0, matrix.size()-1, matrix[0].size()-1);
        return ans;
    }
};
