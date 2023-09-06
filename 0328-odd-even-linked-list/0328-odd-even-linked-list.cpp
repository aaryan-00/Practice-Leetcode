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
        if(head==nullptr) return nullptr;
        ListNode* odd=nullptr,*oddTail=odd;
        ListNode* even=nullptr,*evenTail=even;
        int i=1;
        while(head!=nullptr)
        {
            ListNode* curr=new ListNode(head->val);
            if(i & 1)
            {
                if(odd==nullptr)
                {
                    odd=curr;
                    oddTail=curr;
                }
                else
                {
                    oddTail->next=curr;
                    oddTail=oddTail->next;
                }
            }
            else
            {
                    if(even==nullptr)
                {
                    even=curr;
                    evenTail=curr;
                }
                else
                {
                    evenTail->next=curr;
                    evenTail=evenTail->next;
                }
            }
            i++;
            head=head->next;
        }
        oddTail->next=even;
        return odd;
    }
};