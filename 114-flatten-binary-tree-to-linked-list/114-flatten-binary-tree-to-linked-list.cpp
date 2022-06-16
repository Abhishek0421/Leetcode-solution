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
    void flatten(TreeNode* root) {
        if(!root){
            return ;
        }
        while(root){
            if(!root->left){
                root = root->right;
            }
            else{
                TreeNode* l = root->left;
                while(l->right){
                    l = l->right;
                }
                l->right = root->right;
                root->right = root->left;
                TreeNode* nl = root->left;
                root->left = NULL;
                root = nl;
            }
        }
    }
};
// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         if(!root){
//             return NULL;
//         }
//         while(root){
//             if(!root->right){
//                 root = root->left;
//             }
//             else{
//                 TreeNode* l = root->left;
//                 TreeNode* r = root->right;
//                 if(l){
//                     while(l->right){
//                         l = l->right;
//                     }
//                     if(l->right==NULL){
//                         l->right = r;
//                     }
//                     root->right = root->left;
//                     root->left = NULL;
//                 }
//                 else{
//                     root = root->right;
//                 }
//             }
//         }
//     }
// };