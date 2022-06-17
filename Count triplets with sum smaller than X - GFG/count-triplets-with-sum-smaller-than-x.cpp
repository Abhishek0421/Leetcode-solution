// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	public:
	int bsrch(long long arr[],int start,int end,long long target,int n){
	    while(start<=end){
	        int mid = (start+end)/2;
	        if(arr[mid]==target){
	            return mid;
	        }
	        if(arr[mid]>target){
	            end = mid-1;
	        }
	        else{
	            start = mid+1;
	        }
	    }
	    return start;
	}
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    sort(arr,arr+n);
	    int count=0;
	    for(int i=0;i<n-2;i++){
	        for(int j=i+1;j<n-1;j++){
	            long long x = arr[i],y = arr[j];
	            long long target = sum - (x+y);
	            int k = bsrch(arr,j+1,n-1,target,n);
	           // cout<<j+1<<"->"<<k<<"\n";
	            count = count + (k-(j+1));
	        }
	    }
	    return count;
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
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends