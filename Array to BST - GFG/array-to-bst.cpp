// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    class Node{
        public:
          int data;
          Node* left;
          Node* right;
          Node(int x){
              this->data = x;
              this->left=NULL;
              this->right = NULL;
          }
    };
    Node* solve(vector<int> &num , int start,int end){
        if(start>end){
            return NULL;
        }
        int mid = (start+end)/2;
        Node* root = new Node(num[mid]);
        root->left = solve(num,start,mid-1);
        root->right = solve(num,mid+1,end);
        
        return root;
    }
    void pre(Node* root,vector<int> &v){
        if(root==NULL){
            return;
        }
        v.push_back(root->data);
        pre(root->left,v);
        pre(root->right,v);
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        Node* root = solve(nums,0,nums.size()-1);
        vector<int> v;
        pre(root,v);
        return v;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends