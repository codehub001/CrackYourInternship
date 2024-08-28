/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return head;
        }

        while (head && (head -> val == val)) {
            ListNode *tempNode = head;
            head = head -> next;
            delete tempNode;
        }

        ListNode *prev = head, *curr = head;
        while(curr){
            if(curr->val == val){
                ListNode *tempNode = curr;
                prev -> next = curr -> next;
                curr = curr -> next;
                delete tempNode;                
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
