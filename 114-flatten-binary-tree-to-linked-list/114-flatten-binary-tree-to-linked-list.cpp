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
    TreeNode* last_right(TreeNode* root){
        if(!root->right){
            return root;
        }
        return last_right(root->right);
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* node = root;
        while(node){
            if(node->left){
                TreeNode* right = node->right;
                TreeNode* n = last_right(node->left);
                n->right = node->right;
                node->right = node->left;
                node->left = NULL;
            }
            else{
                node = node->right;
            }
        }
    }
};