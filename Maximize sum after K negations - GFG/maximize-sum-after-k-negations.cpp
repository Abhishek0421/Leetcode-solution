// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a,a+n);
      //  int t=k;
        for(int i=0;i<n;i++){
            if(k>0 && a[i]<=0){
                k--;
                a[i]=-a[i];
            }
        }
        long long int ans = 0;
        sort(a,a+n);
        for(int i=0;i<n;i++){
            ans += a[i];
        }
        if(k!=0){
            if(k%2!=0){
                ans = ans - 2*(a[0]);
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}  // } Driver Code Ends