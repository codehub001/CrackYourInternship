class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        vector<int> prev(heights.size());
        vector<int> next(heights.size());
        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()) prev[i] = st.top();
            else prev[i] = -1;
            st.push(i); 
        }
        while(!st.empty()) st.pop();
        for(int i = heights.size()-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()) next[i] = st.top();
            else next[i] = heights.size();
            st.push(i); 
        }
        int ans = 0;
        int area;
        for(int i = 0; i < heights.size(); i++){
            area = heights[i]*(next[i]-prev[i]-1);
            ans = max(area, ans);
        }
        return ans;
    }
};
