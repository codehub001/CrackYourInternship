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
    ListNode* reverse(ListNode* head){
        ListNode* current = head;
        ListNode *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right){
            return head;
        }

        ListNode* temp = head;
        ListNode* l2 = head;

 

        for(int i = 1; i < right; i++){
            if(i==left-1){
                l2 = temp;
            }
            temp = temp->next;
        }

        ListNode* l3 = temp->next;
        temp->next = NULL;

        if(left == 1){
            l2 = head;
            head = reverse(head);
            l2->next = l3;
            return head;
        }
        l2->next = reverse(l2->next);


        while(l2->next){
            l2 = l2->next;
        }
        l2->next = l3;
        return head;
    }
};
