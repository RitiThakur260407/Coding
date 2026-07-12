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
        int carry = 0;
        int value = l1->val + l2->val;
        carry = value / 10;
        ListNode* head = new ListNode(value % 10);
        ListNode* temp = head;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 || l2) {
            value = carry;
            if (l1) {
                value += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                value += l2->val;
                l2 = l2->next;
            }
            ListNode* newNode = new ListNode(value % 10);
            temp->next = newNode;
            carry = value / 10;
            temp = temp->next;
        }
        if (carry != 0) {
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
        }
        return head;
    }
};