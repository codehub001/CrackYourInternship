class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1, k = nums.size()-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0){
                    k--;
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    ans.push_back({nums[i], nums[j++], nums[k]});
                    while (nums[j] == nums[j-1] && j < k) j++;
                }
            }
        }
        return ans;
    }
};
