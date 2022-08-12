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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        while(root){
            v.push_back(root->val);
            if(!root->left){
                root = root->right;
            }
            else{
                TreeNode* left = root->left;
                while(left->right){
                    left = left->right;
                }
                TreeNode* tempr = root->right;
                root->right = root->left;
                TreeNode* nh = root->left;
                root->left = NULL;
                left->right = tempr;
                root = nh;
            }
        }
        return v;
    }
};