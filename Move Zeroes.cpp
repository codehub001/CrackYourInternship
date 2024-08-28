class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0, i = 0, n = nums.size();
        while(j < n){
            if(nums[j]) swap(nums[i++], nums[j]);
            j++;
        }
    } 
};
