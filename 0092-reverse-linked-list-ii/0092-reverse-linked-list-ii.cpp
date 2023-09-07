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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i=0;
        ListNode* temp=head;
        int before=left-1;
        ListNode* ans=nullptr,*ansTail=nullptr;
        while(before--)
        {
            ListNode* newNode=new ListNode(temp->val);
            if(ans==NULL)
            {
                ans=newNode;
                ansTail=newNode;
            }
            else
            {
                ansTail->next=newNode;
                ansTail=ansTail->next;
            }
            temp=temp->next;
        }
        int diff=right-left+1;
        // cout<<temp->val<<endl;
        ListNode* prev=nullptr,*next=nullptr;
        while(diff--)
        {
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
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
        while(ansTail->next!=nullptr)
        {
            ansTail=ansTail->next;
        }
        ansTail->next=temp;
        
        
        return ans;

    }
};