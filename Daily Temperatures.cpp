class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> st;
        int i = temperatures.size()-1; 
        st.push(i--);

        while(i >= 0){
            if(temperatures[st.top()] > temperatures[i]){
                ans[i] = st.top()-i;
                st.push(i);
                i--;
            }
            else{
                while(!st.empty() && temperatures[st.top()] <= temperatures[i]){
                    st.pop();
                }
                if(!st.empty()){
                    ans[i] = st.top()-i;
                }
                st.push(i);
                i--;
            }
        }
        return ans;
    }
};
