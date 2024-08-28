class Solution {public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum = 0;
        int ans = 0;
        for(int i:nums){
            sum += i;
            sum %= k;
            if(sum < 0){
                sum += k;
            }
            if(!sum){
                ans++;
            }
            ans += mp[sum];
            mp[sum]++;
            // cout<<i<<" -> "<<sum<<" -> "<<ans<<endl;
        }
        return ans;
    }
};
