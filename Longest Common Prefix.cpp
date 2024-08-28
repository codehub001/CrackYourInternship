class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        ans = strs[0];
        for(int i=1; i<strs.size(); i++){
            for(int j=0; j<ans.size(); j++){
                if(strs[i][j] != ans[j]){
                    ans = ans.substr(0, j);
                } 
            }
        }
        return ans;
    }
};
