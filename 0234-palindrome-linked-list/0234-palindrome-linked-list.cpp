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
    ListNode* reverseLL(ListNode* head) {
        if ((!head) || (!head->next))
            return head;

        ListNode* newHead = reverseLL(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        if((head == NULL) || (head -> next == NULL))
        return head ;
        
        ListNode* slow = head;
        ListNode* fast = head->next;

        while ((fast->next) && (fast->next->next)) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverseLL(slow->next);

        ListNode* temp1 = head;
        ListNode* temp2 = newHead;

        while ((temp1) && (temp2)) {
            if (temp1->val != temp2->val) {
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;
    }
};