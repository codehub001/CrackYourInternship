class TrieNode {
public:
    char c;
    vector<TrieNode*> child;
    bool isTerminal;
    TrieNode() {
        child.resize(26, nullptr);
        isTerminal = false;
    }
    TrieNode(char c) {
        this->c = c;
        child.resize(26, nullptr);
        isTerminal = false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insertUtil(TrieNode* root, string& word, int i){
        if(i >= word.length()){
            root->isTerminal = true;
            return;
        }
        if(!root->child[word[i] - 'a']) root->child[word[i] - 'a'] = new TrieNode(word[i]);
        insertUtil(root->child[word[i] - 'a'], word, i+1);
    }
    void insert(string word) {
        insertUtil(root, word, 0);
    }
    
    bool searchUtil(TrieNode* root, string& word, int i){
        if(i >= word.length()) return root->isTerminal;
        if(!root->child[word[i] - 'a']) return false;
        return searchUtil(root->child[word[i] - 'a'], word, i+1);
    }
    bool search(string word) {
        return searchUtil(root, word, 0);
    }

    bool searchWithUtil(TrieNode* root, string& word, int i){
        if(i >= word.length()) return true;
        if(!root->child[word[i] - 'a']) return false;
        return searchWithUtil(root->child[word[i] - 'a'], word, i+1);
    }
    bool startsWith(string prefix) {
        return searchWithUtil(root, prefix, 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
