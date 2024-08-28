//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    void findMaximumNumFun(int ind,string &str,string &ans,int k){
         if(k==0||ind>=str.size()){
            ans=max(str,ans);
            return;
         }
         char mx=str[ind];
         for(int i=ind; i<str.size(); i++){
              if(i==ind){
              findMaximumNumFun(ind+1,str,ans,k);               
              }
              if(str[i]>mx){
              swap(str[ind],str[i]);
              findMaximumNumFun(ind+1,str,ans,k-1); 
              swap(str[ind],str[i]);                  
              }
         } 
    }
    string findMaximumNum(string str, int k)
    {
      string ans;
      int ind=0;
      findMaximumNumFun(ind,str,ans,k);
      return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
