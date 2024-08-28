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
    int height(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int leftH=height(root->left);
        int rightH=height(root->right);
        int maxdepth=max(leftH,rightH) + 1;
        return maxdepth;
    }

    bool isBalanced(TreeNode* root) {
       //base case
       if(root == NULL)
       {
           return true;
       }

       int ans=abs(height(root->left) - height(root->right));
       bool leftAns=isBalanced(root->left);
      bool rigthAns= isBalanced(root->right);
       if(ans<=1 && leftAns && rigthAns)
       {
           return true;
       }
       else return false;
    }
};
