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
    // int pairSum(ListNode* head) {
    //     stack<ListNode*> st;
    //     //finding mid
    //     ListNode *slow = head, *fast = head;
    //     while(fast != NULL && fast->next != NULL)
    //     {
    //         st.push(slow);
    //         fast = fast->next->next;
    //         slow = slow->next;
    //     }
    //     // cout<<st.size()<<endl;
    //     int ans=0;
    //     while(slow!=nullptr)
    //     {
    //         ans=max(ans,st.top()->val+slow->val);
    //         st.pop();
    //         slow=slow->next;
    //     }
    //     return ans;
    // }

    int pairSum(ListNode* head) {
        //finding mid
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        int ans=0;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        while (slow != NULL)
        {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        while(prev)
        {
            ans=max(ans,head->val+prev->val);
            prev=prev->next;
            head=head->next;
        }
        return ans;
    }
};