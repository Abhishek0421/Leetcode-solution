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
    int i=0;
    TreeNode* solve(int s,int e,vector<int> &pre,unordered_map<int,int> &mp){
        if(s>e){
            return NULL;
        }
        int idx = mp[pre[i]];
        TreeNode* root = new TreeNode(pre[i]);
        i++;
        root->left = solve(s,idx-1,pre,mp);
        root->right = solve(idx+1,e,pre,mp);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return solve(0,inorder.size()-1,preorder,mp);
    }
};