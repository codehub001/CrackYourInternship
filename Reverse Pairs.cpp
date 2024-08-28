class Solution {
public:
    void mergeSort(vector<int>& nums, int s, int e, int& pairs){
        if(s == e) return;
        int mid = (s+e)/2;
        mergeSort(nums, s, mid, pairs);
        mergeSort(nums, mid+1, e, pairs);
        int i = s, j = mid+1;
        while(i <= mid && j <= e){
            long long mul = (long long)2*nums[j];
            if(nums[i] > mul){
                pairs += mid-i+1;
                j++;
            }
            else i++;
        }
        merge(nums, s, mid, e);
    }
    void merge(vector<int>& nums, int s, int mid, int e){
        vector<int> res;
        int i = s, j = mid+1;
        while(i <= mid && j <= e){
            if(nums[i] <= nums[j]) res.push_back(nums[i++]);
            else res.push_back(nums[j++]);
        }
        while(i <= mid){
            res.push_back(nums[i++]);
        }
        while(j <= e){
            res.push_back(nums[j++]);
        }
        for(auto i:res){
            nums[s++] = i;
        }
    }
    int reversePairs(vector<int>& nums) {
        int pairs = 0;
        mergeSort(nums, 0, nums.size()-1, pairs);
        return pairs;
    }
};Reverse Pairs
