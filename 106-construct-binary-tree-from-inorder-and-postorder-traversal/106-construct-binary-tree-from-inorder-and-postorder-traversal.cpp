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
    int i;
    TreeNode* solve(int start,int end,unordered_map<int,int> &mp,vector<int> &p){
        if(start>end ){
            return NULL;
        }
        int idx = mp[p[i]];
        TreeNode* root = new TreeNode(p[i--]);
        root->right = solve(idx+1,end,mp,p);
        root->left = solve(start,idx-1,mp,p);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int n = postorder.size();
        i=n-1;
        return solve(0,n-1,mp,postorder);
    }
};