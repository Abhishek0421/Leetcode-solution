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
    int temp,ans=-1;
    void solve(TreeNode* root){
        if(!root){
            return;
        }
        solve(root->left);
        if(temp==1){
            ans = root->val;
        }
        temp--;
        solve(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        temp=k;
        solve(root);
        return ans;
    }
};