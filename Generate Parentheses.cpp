class Solution {
public:
    void solve(int s, int e, vector<string>& ans, string& temp){
        if(!s && !e){
            ans.push_back(temp);
            return;
        }
        if(s){
            temp.push_back('(');
            solve(s-1, e, ans, temp);
            temp.pop_back();
        }
        if(s < e){
            temp.push_back(')');
            solve(s, e-1, ans, temp);
            temp.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        solve(n, n, ans, temp);
        return ans;
    }
};
