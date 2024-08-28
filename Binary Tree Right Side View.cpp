/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int depth(TreeNode* root){
        if(!root) return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
    void solve(TreeNode* root,  vector<int>& ans, int level){
        if(!root) return;
        if(ans[level] == 101) ans[level] = root->val;
        solve(root->right, ans, level+1);
        solve(root->left, ans, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        int dpth = depth(root);
        vector<int> ans(dpth, 101);
        solve(root, ans, 0);
        return ans;
    }
};
