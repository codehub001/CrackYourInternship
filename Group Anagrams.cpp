class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,int> mp;
        int j = 1;
        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(mp[temp]){
                ans[mp[temp]-1].push_back(strs[i]);
            }
            else{
                vector<string> temp2;
                temp2.push_back(strs[i]);
                ans.push_back(temp2);
                mp[temp] = j++;
            }
        }
        return ans;
    }
};
