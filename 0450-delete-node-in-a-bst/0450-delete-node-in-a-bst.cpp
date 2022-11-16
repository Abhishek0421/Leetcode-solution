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
    TreeNode* rightmost(TreeNode* root){
        if(root->right == NULL) return root;
        return rightmost(root->right);
    }
    TreeNode* solve(TreeNode* root){
        if(root->left == NULL) return root->right;
        if(root->right == NULL) return root->left;
        
        TreeNode* r = root->right;
        TreeNode* l = rightmost(root->left);
        l->right = r;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val == key){
            return solve(root);
        }
        TreeNode* ans = root;
        while(root!=NULL){
            if(root->val >key){
                if(root->left && root->left->val == key){
                    root->left = solve(root->left);
                    break;
                }
                else{
                    root = root->left;
                }
            }
            else{
                if(root->right && root->right->val == key){
                    root->right = solve(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }
        }
        return ans;
    }
};