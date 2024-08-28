class Solution {
public:
    bool isPos(vector<int>& nums, int k, int maxi){
        int cnt = 1;
        int sum = 0;
        for(auto i:nums){
            if(sum + i > maxi){
                cnt++;
                sum = i;
            }
            else sum += i;
        }
        return cnt <= k ? true : false;
    }
    int splitArray(vector<int>& nums, int k) {
        int e = accumulate(nums.begin(), nums.end(), 0), s = *max_element(nums.begin(), nums.end()), ans;
        while(s <= e){
            int mid = (e - s)/2 + s;
            if(isPos(nums, k, mid)){
                ans = mid;
                e = mid - 1; 
            }
            else s = mid + 1;
        }
        return ans;
    }
};
