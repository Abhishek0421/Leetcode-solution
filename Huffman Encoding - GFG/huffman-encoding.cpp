// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int x){
            this->data = x;
            this->left = NULL;
            this->right = NULL;
        }
    };
	public:
	    vector<string> ans;
	    void solve(Node* root,string s){
	        if(!root){
	            return;
	        }
	        if(!root->left && !root->right){
	            ans.push_back(s);
	            return ;
	        }
	        if(root->left){
	            solve(root->left,s+to_string(0));
	        }
	        if(root->right){
	            solve(root->right,s+to_string(1));
	        }
	    }
	    struct comp{
            bool operator()(pair<int,Node*> &a,pair<int,Node*> &b){
                return a.first > b.first;
            }
       };
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,comp> pq;
		    for(int i=0;i<N;i++){
		        Node* node = new Node(f[i]);
		        pq.push({node->data,node});
		    }
		    Node* root = NULL;
		    while(pq.size()>=2){
		       auto it1 = pq.top();
		       pq.pop();
		       auto it2 = pq.top();
		       pq.pop();
		       root = new Node(it1.first+it2.first);
		       
		       if(it1.first<=it2.first){
		           root->left = it1.second;
		           root->right = it2.second;
		       }
		       else{
		           root->left = it2.second;
		           root->right = it1.second;
		       }
		       
		       pq.push({root->data,root});
		    }
		    solve(root,"");
		  return ans;
		}
		
};


// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}  // } Driver Code Ends