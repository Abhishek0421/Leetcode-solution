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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<int> ans;
        while(root){
            if(root->left==NULL){
                ans.push_back(root->val);
                root = root->right;
            }
            else{
                TreeNode* l = root->left;
                while(l->right && l->right->val !=root->val){
                    l = l->right;
                }
                if(l->right==NULL){
                    l->right = root;
                    root = root->left;
                }
                else{
                    root->left = NULL;
                }
            }
        }
        return ans;
    }
};