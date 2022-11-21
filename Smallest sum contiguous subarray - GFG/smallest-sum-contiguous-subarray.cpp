// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
      //Code here
      int n = a.size();
      for(int i=0;i<n;i++){
          a[i] = (a[i])*(-1);
      }
      int currmin = a[0];
      int minans = a[0];
      for(int i=1;i<n;i++){
          if(currmin + a[i]>a[i]){
              currmin = currmin + a[i];
              minans = max(minans,currmin);
          }
          else{
              currmin = a[i];
              minans = max(minans,currmin);
          }
      }
      return (-1)*minans;
  }
};


// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}  // } Driver Code Ends