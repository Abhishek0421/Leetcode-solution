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
    void solve(TreeNode* root , long long num ,long long& sum){
    if(root==NULL) return ; 
    num*=10 ; 
    num+=root->val ; 
    if(root->left==NULL && root->right==NULL)sum+=num; 
    solve(root->left,num,sum);
    solve(root->right,num,sum);
}

int sumNumbers(TreeNode* root) {
    if(root==NULL) return 0 ; 
    long long num = 0 ; 
    long long sum = 0 ; 
    solve(root,num,sum) ; 
    
    return int(sum) ;
}
};