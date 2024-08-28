/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        if(head->child){
            head->child = flatten(head->child);
            Node* temp = head->child;
            while(temp->next) temp = temp->next;
            temp->next = head->next;
            head->next = head->child;
            head->child = NULL;
            if(temp->next) temp->next->prev = temp;
            head->next->prev = head;
        } 
        head->next = flatten(head->next);
        return head;
    }
};
