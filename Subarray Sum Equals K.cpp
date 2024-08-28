class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, sum = 0;
        unordered_map<int, int> mp;
        for(auto i : nums){
            sum += i;
            if(sum == k) ans++;
            ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};
