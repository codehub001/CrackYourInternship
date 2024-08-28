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
    bool check=true;
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL){
            return head;
        }
        int len = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            len++;
        }
        if(len < k){
            return head;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        
        int i=0;
        while(curr != NULL && i<k){
            next = curr->next;
            curr->next =prev;
            prev=curr;
            i++;
            curr=next;
        }
        head->next = reverseKGroup(next,k);
        if(i<k-1 && check){
            check = false;
            prev=reverseKGroup(prev,k);
        }
        return prev;
    }
};
