class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* temp = head;
        int len = 1;
        while (temp->next) {
            temp = temp->next;
            len++;
        }
        temp->next = head;
        k = k % len;
        int steps = len - k;
        ListNode* newTail = head;
        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        return newHead;
    }
};