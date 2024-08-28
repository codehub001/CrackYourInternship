class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        ans.push_back(arr);
        while(next_permutation(arr.begin(), arr.end())) ans.push_back(arr);
        return ans;
    }
};
