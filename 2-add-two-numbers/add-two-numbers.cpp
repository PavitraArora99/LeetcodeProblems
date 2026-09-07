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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry != 0) {
            int val1 = (l1 != NULL) ? l1->val : 0;
            int val2 = (l2 != NULL) ? l2->val : 0;

            int totalSum = val1 + val2 + carry;
            carry = totalSum / 10;
            int outDigit = totalSum % 10;

            current->next = new ListNode(outDigit);
            current = current->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead; 
        return result;
    }
};