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
    TreeNode* solve(int s,int e,vector<int> &p,unordered_map<int,int> &mp){
        if(s>e){
            return NULL;
        }
        int idx = mp[p[i]];
        TreeNode* root = new TreeNode(p[i++]);
        root->left = solve(s,idx-1,p,mp);
        root->right = solve(idx+1,e,p,mp);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> in;
        unordered_map<int,int> mp;
        in = preorder;
        sort(in.begin(),in.end());
        int n = in.size();
        for(int i=0;i<n;i++){
            mp[in[i]]=i;
        }
        i=0;
        return solve(0,n-1,preorder,mp);
    }
};