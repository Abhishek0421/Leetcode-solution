// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        vector<int> ans;
        multiset<int> qe;
        for(int i=0;i<=n;i++)
        {
            if(i<k)
            {
                qe.insert(arr[i]);
            }
            else
            {
              ans.push_back(*--qe.end());
              qe.erase(qe.find(arr[i-k]));
            //   if(qe.count(arr[i-k])==1)
            //      qe.erase(arr[i-k]);
            //   else
            //   {
            //      qe.erase(arr[i-k]); 
            //      qe.insert(arr[i-k]);
            //   }
              //if(i<n)
              if(i==n) break;
              qe.insert(arr[i]);
            }
        }
        return ans;
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