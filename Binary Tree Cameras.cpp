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
    // returns 3 - don't have child
    // returns 2 - have camera on the node itself
    // returns 1 - have camera monitoring the node
    // returns 0 - don't have anyone monitoring
    int depth = 0;
    int isMust(TreeNode* root, int& camera){
        if(!root) return 3;
        int left = isMust(root->left, camera);
        int right = isMust(root->right, camera);
        depth++;
        if(!left || !right){
            camera++;
            return 2;
        }
        if(right == 3 && left == 3) return 0;
        if(right == 2 || left == 2) return 1;
        if(left == 3) return right - 1;
        if(right == 3) return left - 1;
        return min(left, right)-1;
    }
    int minCameraCover(TreeNode* root) {
        int camera = 0;
        int temp = isMust(root, camera);
        if(!temp) camera++;
        return camera != 0 ? camera : 1;
    }
};
