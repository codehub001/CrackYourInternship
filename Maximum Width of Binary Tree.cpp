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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            int width = q.back().second - q.front().second + 1;
            ans = max(ans, width);
            long long temp = q.front().second;
            int n = q.size();
            for(int i = 1; i <=n; i++){
                pair<TreeNode*, long long> node = q.front();
                q.pop();
                node.second -= temp;
                if(node.first->left) q.push({node.first->left, node.second*2 + 1});
                if(node.first->right) q.push({node.first->right, node.second*2 + 2});
            }
        }
        return ans;
    }
};
