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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        long long int ans = INT_MIN;
        queue<pair<TreeNode*,long long int> > q;
        q.push({root,0});
        while(q.size()>0){
            int s = q.size();
            long long int f,l;
            for(int i=0;i<s;i++){
                auto it = q.front();
                q.pop();
                long long int c = it.second;
                if(i==0) f = it.second;
                if(i==s-1) l = it.second;
                if(it.first->left){
                    q.push({it.first->left,2*(c-f)+1});
                    
                }
                if(it.first->right){
                    q.push({it.first->right,2*(c-f)+2});
                }
            }
            ans = max(ans,l-f+1);
        }
        return ans;
    }
};