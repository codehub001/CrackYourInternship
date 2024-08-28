class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int i = 0;
        st.push(stoi(tokens[i++]));
        while(i < tokens.size()){
            if(tokens[i] == "+"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num1+num2);
            }
            else if(tokens[i] == "-"){
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                st.push(num1-num2);
            }
            else if(tokens[i] == "*"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num1*num2);
            }
            else if(tokens[i] == "/"){
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                st.push(num1/num2);
            }
            else{
                st.push(stoi(tokens[i]));
            }
            i++;
        }
        return st.top();
    }
};
