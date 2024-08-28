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
