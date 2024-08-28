class Solution {
public:
    int path(int &maxi,TreeNode* root){
        if(!root)
        return 0;
        int l=max(path(maxi,root->left),0);
        int r=max(path(maxi,root->right),0);
        maxi=max(maxi,l+r+root->val);
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        path(maxi,root);
        return maxi;
    }
};
