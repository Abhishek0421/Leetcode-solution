// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int ksize=0,ans = INT_MAX;
        for(int i=0;i<n;i++){
            if(arr[i]<=k){
                ksize++;
            }
        }
        int count=0;
        for(int i=0;i<ksize;i++){
            if(arr[i]>k){
                count++;
            }
        }
        ans = count;
        for(int i=0,j=ksize-1;j<n-1;){
            if(arr[i]>k){
                count--;
            }
            if(arr[j+1]>k){
                count++;
            }
            i++;
            j++;
            ans = min(ans,count);
        }
        return ans;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends