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
    ListNode* middleNode(ListNode* head) {
        //finding mid
        ListNode *slow = head, *fast = head, *prev=NULL;
        while(fast != NULL && fast->next != NULL)
        {
            prev=slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};