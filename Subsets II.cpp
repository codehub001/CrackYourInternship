class Solution {
public:
    void solve(vector<int>& temp, int i, vector<int>& nums, vector<vector<int>>& ans){
        if(i >= nums.size()){
            ans.push_back(temp);
            return;
        }
        int val = nums[i];
        int count = 0;
        while(i < nums.size() && nums[i] == val){
            i++;
            count++;
        } 
        solve(temp, i, nums, ans);
        for(int j = 1; j <= count; j++){
            temp.push_back(val);
            solve(temp, i, nums, ans);  
        }
        for(int j = 1; j <= count; j++){
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(temp, 0, nums, ans);
        return ans;
    }
};
