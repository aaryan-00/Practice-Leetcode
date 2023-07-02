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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<lists.size();i++)
        {
            ListNode *temp=lists[i];
            while(temp!=nullptr)
            {
                pq.push(temp->val);
                temp=temp->next;
            }
        }
        ListNode* head=nullptr;
        ListNode* tail=nullptr;
        while(!pq.empty())
        {
            ListNode* newnode=new ListNode(pq.top());
            pq.pop();
            if(head==nullptr)
            {
                head=newnode;
                tail=newnode;
            }
            else
            {
                tail->next=newnode;
                tail=tail->next;
            }
        }
        return head;
    }
};