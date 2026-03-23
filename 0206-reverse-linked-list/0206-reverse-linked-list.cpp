class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next; // 1. store
            curr->next = prev;           // 2. reverse
            prev = curr;                 // 3. move prev
            curr = next;                 // 4. move curr
        }

        return prev;
    }
};