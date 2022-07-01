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
    unordered_map<int,int> mp;
    vector<int> in;
    void solve(TreeNode* root){
        if(!root) return;
        solve(root->left);
        mp[root->val]++;
        in.push_back(root->val);
        solve(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        in.clear();
        mp.clear();
        solve(root);
        for(int i=0;i<in.size();i++){
            mp[in[i]]--;
            if(mp[k-in[i]]>=1){
                return true;
            }
        }
        return false;
    }
};