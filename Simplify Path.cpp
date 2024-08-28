class Solution {
public:
    string simplifyPath(string path) {
        int i = 0;
        stack<string> st;
        string temp = "";
        while(i < path.size()){
            if(path[i] == '/'){
                if(temp.size() && temp != "."){
                    if(temp == ".."){
                        if(st.size()) st.pop();
                    }
                    else{
                        st.push(temp);
                    }
                } 
                i++;
                temp = "";
            }
            else{
                temp.push_back(path[i++]);
            }
        }
        if(temp.size() && temp != "."){
            if(temp == ".."){
                if(st.size()) st.pop();
            }
            else{
                st.push(temp);
            }
        } 
        stack<string> st2;
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        string ans = "";
        while(!st2.empty()){
            ans.push_back('/');
            ans += st2.top();
            st2.pop();
        }
        if(!ans.size()) ans.push_back('/');
        return ans;
    }
};
