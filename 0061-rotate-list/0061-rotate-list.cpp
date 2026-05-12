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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int n =0;
        if(head==NULL || head->next==NULL) return head;
        while(temp){
            n++;
            temp = temp->next;
        }
        k=k%n;
        if(k==0) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i =0;i<=k;i++){
            fast = fast->next;
        }
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        temp = slow->next;
        slow->next = NULL;
        ListNode* t = temp;
        while(t->next){
            t = t->next;
        }
        t->next = head;
        return temp;

    }
};