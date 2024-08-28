class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char temp;
        int i=0;
        while(i<s.size()){
            if(s[i]=='[' || s[i]=='(' || s[i]=='{'){
                st.push(s[i]);
                i++;
            }
            if(s[i]==']' || s[i]==')' || s[i]=='}'){
                if(st.empty()){
                    return false;
                }
                temp = st.top();
                st.pop();
                if(temp=='[' && s[i]==']'){
                    i++;
                    continue;
                }
                if(temp=='(' && s[i]==')'){
                    i++;
                    continue;
                }
                if(temp=='{' && s[i]=='}'){
                    i++;
                    continue;
                }
                return false;
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};
