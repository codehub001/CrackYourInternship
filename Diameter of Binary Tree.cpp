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

// Approch 1
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(root == NULL){
//             return 0;
//         }
//         int depth = max (maxDepth(root->left), maxDepth(root->right)) + 1;
//         return depth;
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(root==NULL){
//             return 0;
//         }
//         int diameter = max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right));
//         diameter = max(diameter,maxDepth(root->left)+maxDepth(root->right));

//         return diameter;
//     }
// };



//Approch 2
class Solution {
public:
    pair<int,int> diameter(TreeNode* root){
        if(root==NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }

        pair<int,int> left = diameter(root->left);
        pair<int,int> right = diameter(root->right);
        int diameter = max(left.first,max(left.second + right.second, right.first));

        pair<int,int> ans;
        ans.first = diameter;
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).first;
    }
};
