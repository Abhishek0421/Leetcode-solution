// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> v;
       v.push_back(a[0]);
       int idx = 0;
       for(int i=1;i<n;i++){
           if(v[idx] < a[i]){
               v.push_back(a[i]);
               idx++;
           }
           else if(v[idx] > a[i]){
               auto it = upper_bound(v.begin(),v.end(),a[i]);
               if(it!=v.end()){
                   v[it-v.begin()] = a[i];
               }
           }
       }
       return v.size();
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends