//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
  public:
    void inorder(vector<int> &A,vector<int> &v,int n,int index){
        if(index >= n) return;
        
        inorder(A,v,n,2*index+1);
        v.push_back(A[index]);
        inorder(A,v,n,2*index+2);
    }
    int minSwaps(vector<int>&A, int n){
        //Write your code here
        vector<int> a;
        inorder(A,a,n,0);
        vector<pair<int,int> > v(a.size());
        int ans = 0;
        for(int i=0;i<a.size();i++){
            v[i].first = a[i];
            v[i].second = i;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<a.size();i++){
            if(i == v[i].second){
                continue;
            }
            else{
                swap(v[i].first , v[v[i].second].first);
                swap(v[i].second, v[v[i].second].second);
            }
            if(i != v[i].second)
                --i;
            
            ans++;
           // cout<<i<<"\n";
        }
        // for(auto x:v){
        //     cout<<x.second<<" "<<x.first<<" "<<"\n";
        // }
        return ans;
    }
    
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>A(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> A[i];
	    }
	    Solution ob;
	    int ans = ob.minSwaps(A, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends