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
    void solve(TreeNode* root,string &s){
        s = s + to_string(root->val);
        if(!root->left && !root->right){
            return;
        }
        
        if(root->left){
            s = s + "(";
            solve(root->left,s);
            s = s + ")";
        }
        else{
            if(root->right){
                s = s + "()";
            }
        }
        if(root->right){
            s = s + "(";
            solve(root->right,s);
            s = s + ")";
        }
    }
    string tree2str(TreeNode* root) {
        string s ="";
        solve(root,s);
        return s;
    }
};