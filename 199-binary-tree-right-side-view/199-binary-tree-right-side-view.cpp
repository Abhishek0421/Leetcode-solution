/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            int temp=0;
            for(int i=0;i<s;i++){
                auto t = q.front();
                q.pop();
                temp = t->val;
                if(t->left){
                    q.push(t->left);
                }
               // else{
                    if(t->right){
                        q.push(t->right);
                    }
                //}
            }
            v.push_back(temp);
        }
        return v;
    }
};