class TrieNode {
public:
    char c;
    vector<TrieNode*> child;
    int pos;
    TrieNode() {
        child.resize(26, nullptr);
        pos = -1;
    }
    TrieNode(char c) {
        this->c = c;
        child.resize(26, nullptr);
        pos = -1;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insertUtil(TrieNode* root, string& word, int i, int& ind){
        if(i < 0){
            root->pos = ind;
            return;
        }
        if(!root->child[word[i] - 'a']) root->child[word[i] - 'a'] = new TrieNode(word[i]);
        insertUtil(root->child[word[i] - 'a'], word, i-1, ind);
    }
    void insert(string word, int& ind) {
        insertUtil(root, word, word.size()-1, ind);
    }
    bool isPal(string& word, int ind){
        int i = ind, j = word.size()-1;
        while(i < j){
            if(word[i] == word[j]) i++, j--;
            else return false;
        }
        return true;
    }
    void solve(TrieNode* root, string& temp, int& ind, vector<vector<int>>& ans){
        if(root->pos != -1 && root->pos != ind && isPal(temp, 0)) ans.push_back({ind, root->pos});
        for(int i = 0; i < 26; i++){
            if(root->child[i]){
                temp.push_back('a' + i);
                // cout<<temp<<endl;
                solve(root->child[i], temp, ind, ans);
                temp.pop_back();
            }
        }
    }
    void searchUtil(TrieNode* root, string& word, int i, int& ind, vector<vector<int>>& ans){
        if(i >= word.length()){
            string temp = "";
            solve(root, temp, ind, ans);
            return;
        }
        if(!root->child[word[i] - 'a']){
            if(isPal(word, i) && ind != root->pos && root->pos !=  -1){
                ans.push_back({ind, root->pos});
            }
            return;
        }
        if(isPal(word, i) && ind != root->pos && root->pos !=  -1){
            ans.push_back({ind, root->pos});
        }
        searchUtil(root->child[word[i] - 'a'], word, i+1, ind, ans);
    }
    void searchPal(string& word, int& ind, vector<vector<int>>& ans) {
        searchUtil(root, word, 0, ind, ans);
    }
};
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        Trie t;
        for(int i = 0; i < words.size(); i++){
            t.insert(words[i], i);
        }
        for(int i = 0; i < words.size(); i++){
            t.searchPal(words[i], i, ans);
        }
        return ans;
    }
};
