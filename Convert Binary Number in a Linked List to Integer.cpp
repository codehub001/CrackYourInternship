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
 ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        return head;
        ListNode* n=new ListNode(head->val);
        head=head->next;
        while(head!=nullptr)
        {
            ListNode* newnode=new ListNode(head->val,n);
            n=newnode;
            head=head->next;
        }
        return n;
    }
    int getDecimalValue(ListNode* head) {
        head=reverseList(head);
        int p=0;
        int n=0;
        while(head!=nullptr)
        {
            if(head->val==1)
            {
                n+=(1<<p);
            }
            p++;
            head=head->next;
        }
        return n;
    }
};
