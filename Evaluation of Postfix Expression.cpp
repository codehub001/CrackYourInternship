//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        for(auto c:S){
            if(c == '*' || c == '/' || c == '+' || c == '-'){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int res;
                if(c == '*') res = a*b;
                else if(c == '/') res = a/b;
                else if(c == '+') res = a+b;
                else res = a-b;
                st.push(res);
            }
            else st.push((int)c-'0');
        }
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends
