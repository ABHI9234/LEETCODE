class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        bool flag = false;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                flag=true;
                break;
            }
        }
        if(flag==false) return NULL;
        ListNode* t=head;
        while(t!=slow){
            slow = slow->next;
            t = t->next;
        }
        return t;
    }
};