//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class TrieNode {
public:
    char c;
    vector<TrieNode*> child;
    bool isTerminal;

    // Default constructor
    TrieNode() {
        child.resize(26, nullptr); // Initialize with 26 null pointers
        isTerminal = false;
    }

    // Parameterized constructor
    TrieNode(char c) {
        this->c = c;
        child.resize(26, nullptr); // Initialize with 26 null pointers
        isTerminal = false;
    }
};

class WordDictionary {
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void add(TrieNode* root, string& word, int i) {
        if (i >= word.length()) {
            root->isTerminal = true;
            return;
        }
        if (root->child[word[i] - 'a'] != nullptr) {
            add(root->child[word[i] - 'a'], word, i + 1);
        } else {
            root->child[word[i] - 'a'] = new TrieNode(word[i]);
            add(root->child[word[i] - 'a'], word, i + 1);
        }
    }

    void addWord(string word) {
        add(root, word, 0);
    }

    bool srch(TrieNode* root, string& word, int i) {
        if (i >= word.size()) return root->isTerminal;
        if (word[i] == '.') {
            for (int j = 0; j < 26; j++) {
                if (root->child[j] && srch(root->child[j], word, i + 1)) return true;
            }
        } else if (root->child[word[i] - 'a']) return srch(root->child[word[i] - 'a'], word, i + 1);
        return false;
    }

    bool search(string word) {
        return srch(root, word, 0);
    }
};

class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    int isPos(string A, int i, WordDictionary& trie){
        if(i >= A.length()) return 1;
        string temp;
        for(int j = i; j < A.length(); j++){
            temp.push_back(A[j]);
            // cout<<temp<<endl;
            if(trie.search(temp)){
                if(isPos(A, j+1, trie)) return 1;
            } 
        }
        return 0;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        WordDictionary trie;
        for(auto& str:B) trie.addWord(str);
        return isPos(A, 0, trie);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends
