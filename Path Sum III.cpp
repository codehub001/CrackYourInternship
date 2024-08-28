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
    long long solve(TreeNode* root, long long targetSum){
        if(!root) return 0;
        targetSum -= root->val;
        int ans = 0;
        if(targetSum == 0) ans++;
        return  ans + solve(root->left, targetSum) + solve(root->right, targetSum);
    }
    int pathSum(TreeNode* root, long long targetSum) {
        if(!root) return 0;
        int ans = solve(root, targetSum);
        ans += pathSum(root->left, targetSum);
        ans += pathSum(root->right, targetSum);        
        return ans;
    }
};
