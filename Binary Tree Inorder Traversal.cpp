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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<int> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            while(!root){
                st.push(root);
                root = root->left;
            }
            ans.push_back(st.top()->val);
            TreeNode* temp = st.top();
            if(!root->right) st.top()
        }
    }
};
