bool cmp(vector<int>& a, vector<int>& b){
    if(a[1] == b[1]) return a[0] > b[0];
    return a[1] < b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 0;
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] >= end) end = intervals[i][1];
            else ans++;
        }
        return ans;
    }
};
