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
        int n =1;
        if(head==NULL || head->next==NULL) return head;
        while(temp->next){
            n++;
            temp = temp->next;
        }
        k=k%n;
        if(k==0) return head;
        temp->next = head;
        ListNode* fast = head;
        for(int i =0;i<n-k-1;i++){
            fast = fast->next;
        }
        
       ListNode* newHead = fast->next;
       fast->next = NULL;
       return newHead;

    }
};