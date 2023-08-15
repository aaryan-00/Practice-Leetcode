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
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr) return nullptr;
        ListNode *less=NULL,*after=NULL, *lessTail=NULL,*afterTail=NULL;
        while(head!=NULL)
        {
            ListNode* curr=new ListNode(head->val);
            if(head->val<x)
            {
                if(less==NULL)
                {
                    less=curr,lessTail=curr;
                }
                else
                {
                    lessTail->next=curr;
                    lessTail=lessTail->next;
                }
                
            }
            else
            {
                if(after==NULL)
                {
                    after=curr,afterTail=curr;
                }
                else
                {
                    afterTail->next=curr;
                    afterTail=afterTail->next;
                }
            }
            head=head->next;
        }
        if(less==nullptr) return after;
        else if(after==nullptr) return less;
        lessTail->next=after;
        return less;
    }
};