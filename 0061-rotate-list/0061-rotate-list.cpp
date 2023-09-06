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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return nullptr;
        int sz=0;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            sz++;
            temp=temp->next;
        }

        k=k%sz;
        if(k==0) return head;
        int rem=sz-k;
        rem--;
        ListNode* iter=head;
        while(rem--)
        {
            iter=iter->next;   
        }
        // cout<<iter->val<<endl;
        ListNode* ans=iter->next;
        cout<<ans->val<<endl;
        cout<<head->val<<endl;
        iter->next=nullptr;
        ListNode* goo=ans;
        while(goo->next!=nullptr)
        {
            goo=goo->next;
        }
        goo->next=head;
        return ans;
    }
};