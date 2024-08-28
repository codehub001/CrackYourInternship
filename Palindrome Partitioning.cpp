class Solution {
public:
    bool isPal(string& str){
        for(int i = 0; i < str.length()/2; i++){
            if(str[i] != str[str.length()-1-i]){
                return false;
            }
        }
        return true;
    }
    void solve(string& s, int i, string& str, vector<string>& temp, vector<vector<string>>& ans){
        if(i >= s.length()){
            if(str.size() && isPal(str)){
                temp.push_back(str);
                ans.push_back(temp);
                temp.pop_back();
            }
            return;
        }
        str.push_back(s[i]);
        if(isPal(str)){
            temp.push_back(str);
            str = "";
            solve(s, i+1, str, temp, ans);
            str = temp.back();
            temp.pop_back();
        }
        solve(s, i+1, str, temp, ans);
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        string str = "";
        solve(s, 0, str, temp, ans);
        return ans;
    }
};
