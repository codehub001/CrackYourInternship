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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        
        ListNode* temp = odd;
        ListNode* temp2 = even;
        head = head->next->next;

        while(head){
            temp->next = head;
            head = head->next;
            temp = temp->next;
            if(head){            
                temp2->next = head;
                head = head->next;
                temp2 = temp2->next;
            }
            else{
                temp2->next = NULL;
            }
        }
        
        temp->next = even;

        return odd;

    }
};
