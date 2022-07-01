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
    void inorder(TreeNode* root, unordered_map<int,int>& m, int k,bool& ans){
        if(!root) return;
        inorder(root->left,m,k,ans);
        m[root->val]++;
        if(m[k-root->val] and (k-root->val!=root->val)){
            ans=true;
            return;
        }
        inorder(root->right,m,k,ans);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> m;
        bool ans=false;
        inorder(root,m,k,ans);
        return ans;
        
    }
};