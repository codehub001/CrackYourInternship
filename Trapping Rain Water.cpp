class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lh(n, 0);
        vector<int> rh(n, 0);

        int l = height[0], r = height[n-1];

        for(int i = 1; i < n; i++){
            lh[i] = l;
            rh[n-i-1] = r;
            l = max(l, height[i]);
            r = max(r, height[n-i-1]);
        }
        int ans = 0, vol = 0;
        for(int i = 1; i < n-1; i++){
            vol = min(lh[i], rh[i]) - height[i];
            if(vol > 0){
                ans += vol;
            }
        }
        return ans;        
    }
};
