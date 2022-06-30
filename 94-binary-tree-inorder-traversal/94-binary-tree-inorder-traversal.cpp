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
        if(!root){
            return {};
        }
        vector<int> v;
        while(root){
            if(!root->left){
                v.push_back(root->val);
                root = root->right;
            }
            else{
                TreeNode* left = root->left;
                while(left->right){
                    left = left->right;
                }
                left->right = root;
                TreeNode* l = root->left;
                root->left=NULL;
                root = l;
            }
        }
        return v;
    }
};