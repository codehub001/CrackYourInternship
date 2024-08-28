class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0], count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == ans){
                count++;
            }
            else if(count){
                count--;
            }
            else{
                count++;
                ans = nums[i];
            }
        }
        return ans;
    }
};
