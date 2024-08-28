class Solution {
public:
    void mergeSort(vector<pair<int,int>>& nums, unordered_map<int,int>& ans, int i, int j){
        if(i >= j) return;
        int mid = (i+j)/2;
        mergeSort(nums, ans, i, mid);
        mergeSort(nums, ans, mid + 1, j);
        merge(nums, ans, i, j);
    }
    void merge(vector<pair<int,int>>& nums, unordered_map<int,int>& ans, int s, int e){
        // cout<<s<<" "<<e<<endl;
        int mid = (s+e)/2;
        int i = s, j = mid + 1;
        int count = 0;
        vector<pair<int,int>> temp;
        while(i <= mid && j <= e){
            if(nums[i].first <= nums[j].first){
                ans[nums[i].second] += count;
                temp.push_back(nums[i++]);
            }
            else{
                count++;
                temp.push_back(nums[j++]);
            }
        }
        while(i <= mid){
            ans[nums[i].second] += count;
            temp.push_back(nums[i++]);
        }
        while(j <= e){
            temp.push_back(nums[j++]);
        }
        for(i = 0; i < temp.size(); i++){
            nums[i+s] = temp[i];
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<pair<int,int>> temp(nums.size());
        for(int i = 0; i < temp.size(); i++){
            temp[i] = {nums[i], i} ;
        }
        mergeSort(temp, mp, 0, nums.size()-1);
        for(int i = 0; i < nums.size(); i++){
            nums[i] = mp[i];
        }
        return nums;
    }
};
