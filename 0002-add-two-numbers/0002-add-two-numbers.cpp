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
    ListNode *addTwoNumbers(ListNode *A, ListNode *B)
    {
        ListNode *head = NULL, *tail = NULL;
        int carry = 0, sum = 0;
        while (A != NULL || B != NULL)
        {
            sum = carry;
            if (A != NULL)
                sum = sum + A->val;
            // else sum+=0;
            if (B != NULL)
                sum = sum + B->val;
            // else sum+=0;
            if (sum >= 10)
                carry = 1;
            else
                carry = 0;
            sum = sum % 10;
            ListNode *newNode = new ListNode(sum);
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = tail->next;
            }
            if (A != NULL)
                A = A->next;
            if (B != NULL)
                B = B->next;
        }
        if (carry > 0)
        {
            ListNode *newNode = new ListNode(carry);
            tail->next = newNode;
        }
        return head;
    }
};