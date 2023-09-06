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
    int pairSum(ListNode* head) {
        stack<ListNode*> st;
        //finding mid
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            st.push(slow);
            fast = fast->next->next;
            slow = slow->next;
        }
        // cout<<st.size()<<endl;
        int ans=0;
        while(slow!=nullptr)
        {
            ans=max(ans,st.top()->val+slow->val);
            st.pop();
            slow=slow->next;
        }
        return ans;
    }
};