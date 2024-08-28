class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        stack<string> st2;
        int i = 0;
        string temp = "";
        while(i < s.length()){
            if(s[i] == ']'){
                temp = "";
                while(!isdigit(st.top()[0])){
                    st2.push(st.top());
                    st.pop();
                }
                while(!st2.empty()){
                    temp += st2.top();
                    st2.pop();
                }
                int k = stoi(st.top());
                st.pop();
                string ans = "";
                while(k--){
                    ans += temp;
                }
                st.push(ans);
                i++;

            }
            else if(isdigit(s[i])){
                temp = "";
                while(isdigit(s[i])){
                    temp.push_back(s[i++]);
                }
                st.push(temp);
                i++;
            }
            else{
                temp = "";
                while(i < s.length() && s[i] >= 'a' && s[i] <= 'z'){
                    temp.push_back(s[i++]);
                }
                st.push(temp);
            }
        }
        string ans = "";
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        while(!st2.empty()){
            cout<<st2.top()<<endl;
            ans += st2.top();
            st2.pop();
        }
        return ans;
    }
};
