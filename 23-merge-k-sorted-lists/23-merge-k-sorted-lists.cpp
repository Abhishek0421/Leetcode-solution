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
    ListNode* merge(ListNode* l1,ListNode* l2){
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        ListNode* node = new ListNode(-1);
        ListNode* n = node;
        while(l1 && l2){
            if(l1->val > l2->val){
                node->next = l2;
                node = l2;
                l2 = l2->next;
            }
            else{
                node->next = l1;
                node = l1;
                l1 = l1->next;
            }
        }
        if(l1==NULL){
            node->next = l2;
            return n->next;
        }
        node->next = l1;
        return n->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0){
            return NULL;
        }
        if(k==1){
            return lists[0];
        }
        for(int i=1;i<k;i++){
            lists[i] = merge(lists[i],lists[i-1]);
        }
        return lists[k-1];
    }
};