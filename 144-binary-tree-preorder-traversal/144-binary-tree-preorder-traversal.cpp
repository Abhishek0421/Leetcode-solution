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
        if(root==NULL){
            return {};
        }
        vector<int> v;
        while(root){
            v.push_back(root->val);
            if(!root->left){
                root = root->right;
            }
            else{
                TreeNode* l = root->left;
                TreeNode* r = root->right;
                while(l->right){
                    l = l->right;
                }
                l->right = r;
                TreeNode* temp = root->left;
                root->left=NULL;
                root = temp;
            }
        }
        return v;
    }
};