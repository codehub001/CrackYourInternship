/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "N";
        string ans = "";
        ans += to_string(root->val);
        cout<<ans<<endl;
        ans += ",";
        ans += serialize(root->left);
        ans += serialize(root->right);
        // cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* solve(string& data, int& i){
        // cout<<i;
        if(i >= data.size() || data[i] == 'N'){
            i++;
            return NULL;
        } 
        // cout<<i<<endl;
        if(data[i] == ',') {
            i++;
            return solve(data, i);
        }
        string num;
        while(i < data.size() && (isdigit(data[i]) || data[i] == '-')){
            num.push_back(data[i++]);
        }
        TreeNode* root = new TreeNode(stoi(num));
        root->left = solve(data, i);
        root->right = solve(data, i);
        return root;
    }
    TreeNode* deserialize(string data) {
        int i = 0;
        return solve(data, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
