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
    void remove(ListNode*& head, int n, int& i){
        if(head == NULL){
            return;
        }
        remove(head->next,n,i);
        i++;
        if(i == n){
            head = head->next;
            return;
        }
        if(i > n){
            return;
        }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i =0;
        remove(head,n,i);
        return head;
    }
};
