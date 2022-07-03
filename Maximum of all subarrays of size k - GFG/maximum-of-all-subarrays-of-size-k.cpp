// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    int max_(int* arr, int a, int b, int& maxi)
   {
       int ans = INT_MIN;
       for(int i = a; i < b; i++)
       {
           if(arr[i] >= ans)
           {
               maxi = i;
               ans = arr[i];
           }
       }
       return ans;
   }
   vector <int> max_of_subarrays(int *arr, int n, int k)
   {
       vector<int> ans;
       int t = 0;
       ans.push_back(max_(arr, 0, k, t));
       for(int i = 1; i < n-k+1; i++)
       {
           if(t >= i)
           {
               if(arr[i+k-1] >= arr[t])
               {
                   ans.push_back(arr[i+k-1]);
                   t = i+k-1;
               }
               else
               {
                   ans.push_back(arr[t]);
               }
           }
           else
           {
               ans.push_back(max_(arr, i, i+k, t));
           }
       }
       return ans;
   }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends