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
    ListNode* add(ListNode* ans, ListNode* l1, ListNode* l2, int carry){
        if(l1 == NULL && l2 == NULL){
            if(carry){
                ans = new ListNode(carry);
            }
            return ans;
        }
        if(l1 == NULL){
            ans = new ListNode((l2->val + carry)%10);
            carry = (l2->val + carry)/10;
            ans->next = add(ans->next, l1, l2->next, carry);
            return ans;      
        }
        if(l2 == NULL){
            ans = new ListNode((l1->val + carry)%10);
            carry = (l1->val + carry)/10;
            ans->next = add(ans->next, l1->next, l2, carry);
            return ans;              
        }
        ans = new ListNode((l1->val + l2->val + carry)%10);
        carry = (l1->val +l2->val + carry)/10;
        ans->next = add(ans->next, l1->next, l2->next, carry);
        return ans; 
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans;
        return add(ans, l1, l2, 0);
    }
};
