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
    bool hasPathSum(TreeNode* root, int targetSum, bool flag = false) {
        if(!root) return !targetSum && flag;
        targetSum -= root->val;
        return hasPathSum(root->left, targetSum, root->right == NULL) || hasPathSum(root->right, targetSum, root->left == NULL);
    }
};
