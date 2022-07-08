// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> v(n);
	    v[0] = arr[0];
	    int ans = v[0];
	    for(int i=1;i<n;i++){
	        int mx = arr[i];
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i]){
	                mx = max(mx,arr[i]+v[j]);
	            }
	        }
	       // if(mx == INT_MIN){
	       //     v[i] = arr[i];
	       // }
	       // else{
	            ans = max(ans,mx);
	            v[i] = mx;
	           // cout<<mx<<"\n";
	       // }
	    }
	    return ans;
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends