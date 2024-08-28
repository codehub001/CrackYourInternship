class Solution {
public:
    void solve(vector<int>& candidates, int i, int target, set<vector<int>>& ans, vector<int>& temp){
        if(target < 0){
            return;
        }
        if(target == 0){
            ans.insert(temp);
            return;
        }
        if(i >= candidates.size() || candidates[i] > target){
            return;
        }
        int val = candidates[i];
        int count = 0;
        while(i < candidates.size() && candidates[i] == val){
            i++;
            count++;
        } 
        solve(candidates, i, target, ans, temp);
        for(int j = 1; j <= count; j++){
            temp.push_back(val);
            target -= val;
            solve(candidates, i, target, ans, temp);
        }
        for(int j = 1; j <= count; j++){
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> temp_ans;
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, 0, target, temp_ans, temp);
        for(auto &i : temp_ans) ans.push_back(i);
        return ans;
    }
};
