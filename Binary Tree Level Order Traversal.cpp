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
    void solve(TreeNode* root, vector<vector<int>>& ans, int i){
        if(root == NULL){
            return;
        }
        ans[i].push_back(root->val);
        solve(root->left, ans, i+1);
        solve(root->right, ans, i+1);
    }
    int findLevels(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int ans = max(findLevels(root->left), findLevels(root->right))+1;
        return ans;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int levels = findLevels(root);
        vector<vector<int>> ans(levels);
        int i = 0;
        solve(root, ans, i);
        return ans;
        
    }
};
