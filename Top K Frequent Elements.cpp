class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(const auto& i:nums) freq[i]++;
        priority_queue<pair<int,int>> pq;
        for(const auto& i:freq) pq.push(make_pair(i.second, i.first));
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
