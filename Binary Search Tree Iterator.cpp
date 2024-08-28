class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        inorderTraversal(root);
    }
    int next() {
        int val = nodes.front();
        nodes.pop_front();
        return val;
    }
    bool hasNext() {
        return !nodes.empty();
    }
private:
    std::deque<int> nodes;
    
    void inorderTraversal(TreeNode* node) {
        if (!node) return;
        inorderTraversal(node->left);
        nodes.push_back(node->val);
        inorderTraversal(node->right);
    }
};
