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
    int ans;
    int solve(TreeNode* root,int &ans){
        if(!root){
            return 0;
        }
        int l = solve(root->left,ans);
        int r = solve(root->right,ans);
        if(root->val > ans){
            ans = root->val;
        }
        if(root->val +l > ans){
            ans = root->val + l;
        }
        if(root->val + r > ans){
            ans = root->val + r;
        }
        if(root->val + l+r > ans){
            ans = root->val + r+l;
        }
        if(root->val > max(l,r)+root->val){
            return root->val;
        }
        return max(l,r)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root,ans);
        return ans;
    }
};