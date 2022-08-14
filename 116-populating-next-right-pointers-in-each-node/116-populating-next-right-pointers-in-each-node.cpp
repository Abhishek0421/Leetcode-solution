/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*> q;
        q.push(root);
        //root->next=NULL;
        
        while(!q.empty()){
            int s = q.size();
            Node* next = NULL;
            for(int i=0;i<s;i++){
                Node* t = q.front();
                q.pop();
                t->next = next;
                next = t;
                if(t->right){
                    q.push(t->right);
                }
                if(t->left){
                    q.push(t->left);
                }
            }
        }
        return root;
    }
};