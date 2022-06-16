// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    bool bsrch(vector<int> &arr,int start,int end,int target){
        int i=start;
        int j=end;
        while(i<=j){
            int mid = (i+j)/2;
            if(arr[mid]==target){
                return true;
            }
            if(arr[mid]>target){
                return bsrch(arr,i,mid-1,target);
            }
            else{
                return bsrch(arr,mid+1,j,target);
            }
        }
        return false;
    }
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        
        unordered_map<int,int> mp;
        set<vector<int>> st;
        int n = arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int l=j+1;l<n;l++){
                    int x = arr[i],y=arr[j],z=arr[l];
                    int target = k - (arr[i]+arr[j]+arr[l]);
                    if(bsrch(arr,l+1,n-1,target)){
                        vector<int> v = {x,y,z,target};
                        st.insert(v);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends