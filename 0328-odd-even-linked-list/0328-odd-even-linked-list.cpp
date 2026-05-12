class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* t1=head;
        ListNode* t2 = head->next;
        ListNode* t3 = head->next;
        while(t2 != NULL && t2->next!=NULL){
            t1->next = t2->next;
            t1 = t1->next;
            t2->next = t1->next;
            t2 = t2->next;
        }
        t1->next = t3;
        return head;
    }
};