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
    ListNode* merge(ListNode* head1,ListNode* head2){
        if(head1 == NULL){
            return head2;
        }
        if(head2 == NULL){
            return head1;
        }
        ListNode* res = NULL;
        ListNode* h1 = new ListNode(-1);
        res = h1;
        while(head1!=NULL && head2!=NULL){
            if(head1->val > head2->val){
                h1->next = head2;
                h1 = h1->next;
                head2 = head2->next;
            }
            else{
                h1->next = head1;
                h1 = h1->next;
                head1 = head1->next;
            }
        }
        if(head1!=NULL){
            h1->next = head1;
        }
        if(head2!=NULL){
            h1->next = head2;
        }
        return res->next;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* m  = NULL;
        for(int i=0;i<lists.size();i++){
            m = merge(m,lists[i]);
        }
        return m;
    }
};