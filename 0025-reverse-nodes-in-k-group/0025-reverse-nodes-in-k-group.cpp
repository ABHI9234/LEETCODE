class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 1. Check if there are at least k nodes left
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            if (!curr) return head; // Less than k nodes, keep as is
            curr = curr->next;
        }

        // 2. Reverse the first k nodes
        ListNode* prev = nullptr;
        ListNode* nextNode = nullptr;
        curr = head; // Start back at the head
        
        for (int i = 0; i < k; i++) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // 3. 'head' is now the tail of our reversed group.
        // Connect it to the result of the next k-group reversal.
        if (nextNode != nullptr) {
            head->next = reverseKGroup(nextNode, k);
        }

        // 4. 'prev' is the new head of this reversed k-group
        return prev;
    }
};