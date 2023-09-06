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
    bool isPalindrome(ListNode* head) {
        //finding mid
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
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
            if(head->val!=prev->val) return false;
            prev=prev->next;
            head=head->next;
        }
        return true;
    }
};