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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> mp;
        int lev=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
       // int a=0;
        while(q.size()>0){
            int s = q.size();
            for(int i=0;i<s;i++){
                auto it = q.front();
                q.pop();
                int a = it.second;
                TreeNode* t = it.first;
                mp[a][lev].push_back(t->val);
                if(t->left){
                    q.push({t->left,a-1});
                }
                if(t->right){
                    q.push({t->right,a+1});
                }
            }
            lev++;
        }
        vector<vector<int>> v;
        for(auto x:mp){
            vector<int> temp;
            for(auto y:x.second){
                sort(y.second.begin(),y.second.end());
                for(auto t:y.second){
                    temp.push_back(t);
                }
            }
            v.push_back(temp);
        }
        return v;
    }
};