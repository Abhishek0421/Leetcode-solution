// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        map<int,int> mp;
        vector<int> v;
        for(int i=0;i<k;i++){
            mp[arr[i]]++;
            if(i==k-1){
                v.push_back((--mp.end())->first);
            }
        }
        for(int i=k;i<n;i++){
            mp[arr[i]]++;
            mp[arr[i-k]]--;
            if(mp[arr[i-k]]==0){
                mp.erase(arr[i-k]);
            }
            v.push_back((--mp.end())->first);
        } 
        return v;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends