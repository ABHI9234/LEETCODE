class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast!=NULL) slow = slow->next;
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
        int mx = INT_MIN;
        while(prev){
            mx = max(mx,prev->val+temp->val);
            prev = prev->next;
            temp = temp->next;
        }
        return mx;

        
    }
};