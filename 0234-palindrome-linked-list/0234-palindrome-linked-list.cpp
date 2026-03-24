class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast!=NULL){
            slow=slow->next;
        }
        ListNode* c= slow;
        ListNode* prev = NULL;
        ListNode* curr = c;
        ListNode* Next = c;
        while(curr){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        while(prev){
            if(temp->val != prev->val) return false;
            temp = temp->next;
            prev = prev->next;
        }
        return true;
    }
};