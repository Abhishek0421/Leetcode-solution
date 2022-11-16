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
    ListNode* rev(ListNode* head){
        if(!head) return NULL;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* curr = head;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode* h1 = head;
        ListNode* h2 = head;
        for(int i=0;i<k-1;i++){
            h1 = h1->next;
            if(!h1) return h2;
        }
        ListNode* h3 = h1->next;
        h1->next = NULL;
        ListNode* t = h2;
        ListNode* nh = rev(h2);
        h2->next  = reverseKGroup(h3,k);
        return nh;
    }
};