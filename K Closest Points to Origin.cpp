bool cmp(vector<int>& a, vector<int>& b){
    long long dist1 = (a[0])*(a[0]);
    dist1 += (a[1])*(a[1]);
    long long dist2 = (b[0])*(b[0]);
    dist2 += (b[1])*(b[1]);
    return dist1 < dist2;
}
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), cmp);
        vector<vector<int>> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(points[i]);
        }
        return ans;
    }
};
