//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
    struct TrieNode{
        TrieNode *child[26];
        bool isEnd;
        TrieNode(){
            for(int i=0; i<26; i++)
                child[i]=NULL;
            isEnd=false;
        }
    };
    class Trie{
        TrieNode *root;
        public:
        Trie(){
            root=new TrieNode();
        }
        void insert(string &s){
            TrieNode *curr=root;
            for(int i=0; i<s.length(); i++){
                int index=s[i]-'a';
                if(curr->child[index]==NULL)
                    curr->child[index]= new TrieNode();
                curr=curr->child[index];
            }
            curr->isEnd=true;
        }
        void dfs(string s, TrieNode *curr, vector<string> &vec){
            if(curr->isEnd==true)
                vec.push_back(s);
            for(int i=0; i<26; i++){
                if(curr->child[i]!=NULL){
                    s+=('a'+i);
                    dfs(s, curr->child[i], vec);
                    s.pop_back();
                }
            }
        }
        vector<string> findit(string pre){
            TrieNode *curr=root;
            for(int i=0; pre[i]!='\0'; i++){
                int idx=pre[i]-'a';
                if(curr->child[idx]==NULL)
                    return {"0"};
                else
                    curr=curr->child[idx];
            }
            vector<string> vec;
            dfs(pre, curr, vec);
            return vec;
        }
    };
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> ans;
        Trie trie;
        for(int i=0; i<n; i++)
            trie.insert(contact[i]);
        for(int i=0; i<s.length(); i++)
            ans.push_back(trie.findit(s.substr(0, i+1)));
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < ans.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code EndsPhone directory
