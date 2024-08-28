class NumArray {
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            nums[i] += nums[i-1];
        }
        this->nums = nums;
    }
    
    int sumRange(int left, int right) {
        int prev = left == 0 ? 0 : nums[left-1];
        // cout<<prev<<" "<<nums[right]<<endl;
        return nums[right] - prev;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
