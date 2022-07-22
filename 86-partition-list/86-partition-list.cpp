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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* l = new ListNode(-1);
        ListNode* g = new ListNode(-1);
        
        ListNode* l1=l;
        ListNode* g1=g;
        
        
        while(head){
            if(head->val>=x){
                g->next = head;
                g = head;
            }
            else{
                l->next = head;
                l = head;
            }
            head=head->next;
        }
        g->next=NULL;
        if(l1->next){
            l->next = g1->next;
            return l1->next;
        }
        return g1->next;
    }
};