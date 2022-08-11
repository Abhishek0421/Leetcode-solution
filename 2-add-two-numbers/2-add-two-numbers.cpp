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
    ListNode* rev(ListNode* head,ListNode* prev){
        if(!head) return prev;
        ListNode* next = head->next;
        head->next = prev;
        return rev(next,head);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        int c = 0;
        ListNode* n = new ListNode(0);
        ListNode* res = n;
        while(h1 || h2 || c){
            int a=0,b=0;
            if(h1){
                a = h1->val;
            }
            if(h2){
                b = h2->val;
            }
            ListNode* t = new ListNode((a+b+c)%10);
            c = (a+b+c)/10;
            n->next = t;
            n = n->next;
            if(h1){
                h1=h1->next;
            }
            if(h2){
                h2=h2->next;
            }
        }
        return res->next;
    }
};