class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char> st;
        stack<int> cnt;
        int curr = 0;
        for(auto c:s){

            if(!st.empty() && st.top() == c){
                if(curr == k-1){
                    while(curr--) st.pop();
                    if(!cnt.empty()){
                        curr = cnt.top();
                        cnt.pop();
                    }
                }
                else{
                    curr++;
                    st.push(c);
                }
                continue;
            } 
            else if(!st.empty())  cnt.push(curr);
            curr = 1;
            st.push(c);
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
