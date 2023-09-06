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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int sz=0;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            sz++;
            temp=temp->next;
        }
        // cout<<sz<<endl;
        int rem=sz%k;
        int val=sz/k;
        vector<ListNode*> ans;
        while(k--)
        {
            int curr=val+(rem>0);
            rem--;
            ListNode* res=nullptr, *tail=nullptr;
            while(curr-- && head!=nullptr)
            {
                ListNode* newNode=new ListNode(head->val);
                if(res==nullptr)
                {
                    res=newNode;
                    tail=newNode;
                }
                else
                {
                    tail->next=newNode;
                    tail=tail->next;
                }
                head=head->next;
            }
            ans.push_back(res);

        }
        return ans;
    }
};