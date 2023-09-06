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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr) return nullptr;
        int sz=0;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            sz++;
            temp=temp->next;
        }
        if(sz==1) return nullptr;
        if(n==sz) return head->next;
        int rem=sz-n;
        rem--;
        ListNode* iter=head;
        while(rem--)
        {
            iter=iter->next;   
        }
        ListNode* nexti=iter->next->next;
        ListNode* todelete=iter->next;
        delete(todelete);
        iter->next=nexti;

        
        return head;
    }
};