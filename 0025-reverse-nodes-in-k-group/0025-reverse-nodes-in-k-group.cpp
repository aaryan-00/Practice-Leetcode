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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int sz=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            sz++;
            temp=temp->next;
        }
        int loop=sz/k;
        // cout<<loop<<endl;
        ListNode* ans=nullptr,*ansTail=nullptr;
        while(loop--)
        {
            ListNode* prev=nullptr,*next=nullptr;
            int K=k;
            while(K--)
            {
                next = head->next;
                head->next = prev;
                prev = head;
                head = next;
            }
            if(ans==NULL)
            {
                ans=prev;
                ansTail=prev;
            }
            else
            {
                ansTail->next=prev;
                ansTail=ansTail->next;
            }
            while(ansTail->next!=NULL)
            {
                ansTail=ansTail->next;
            }
        }
        ansTail->next=head;
        return ans;
    }
};