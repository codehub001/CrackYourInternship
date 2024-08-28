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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        stack<TreeNode*> st1, st2;
        st1.push(root);
        TreeNode* node;
        while(!st1.empty()){
            if(!st1.empty()){
                int n = st1.size();
                vector<int> temp;
                for(int i = 1; i <= n; i++){
                    node = st1.top();
                    st1.pop();
                    temp.push_back(node->val);
                    if(node->left) st2.push(node->left);
                    if(node->right) st2.push(node->right);
                }
                ans.push_back(temp);
            }
            if(!st2.empty()){
                int n = st2.size();
                vector<int> temp;
                for(int i = 1; i <= n; i++){
                    node = st2.top();
                    st2.pop();
                    temp.push_back(node->val);
                    if(node->right) st1.push(node->right);
                    if(node->left) st1.push(node->left);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
