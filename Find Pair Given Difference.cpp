class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int i = 0, j = 0, ans = 0;
        sort(nums.begin(), nums.end());
        while(j < nums.size()){
            if(j == i) j++;
            else if(nums[j] - nums[i] > k) i++;
            else if(nums[j] - nums[i] < k) j++;
            else{
                ans++;
                j++;
                while(j < nums.size() && nums[j] == nums[j-1]){
                    j++;
                }
            }
        }
        return ans;
    }
};
