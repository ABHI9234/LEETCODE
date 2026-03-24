class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* c = head->next;
        while(b!=NULL && b->next!=NULL){
            a->next = a->next->next;
            b->next = b->next->next;
            a= a->next;
            b=b->next;
        }
        a->next = c;
        return head;
    }
};