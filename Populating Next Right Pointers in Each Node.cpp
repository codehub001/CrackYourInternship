/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    queue<Node*> q;
public:
    Node* connect(Node* root) {
        if(!root) return root;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 1; i < n; i++){
                Node* first = q.front();
                q.pop();
                first->next = q.front();
                if(first->left) q.push(first->left);
                if(first->right) q.push(first->right);
            }
            Node* first = q.front();
            q.pop();
            if(first->left) q.push(first->left);
            if(first->right) q.push(first->right);
        }
        return root;
    }
};
