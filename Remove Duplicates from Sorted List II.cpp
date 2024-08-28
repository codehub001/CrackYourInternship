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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        ListNode* i = head;

        while(i != NULL){
            if(i->next == NULL || i->val != i->next->val){
                temp->next = i;
                temp = temp->next;
                i = i->next;
            }
            else{
                while(i->next != NULL && i->val == i->next->val){
                    i = i->next;
                }
                i = i->next;
            }
        }
        temp->next = NULL;
        return ans->next;
    }
};
