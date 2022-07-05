// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool is_possible(int arr[],long long int mid,int n,int k){
        int partitions=1;
        int i=0;
        long long int temp=0;
        while(i<n){
            if(temp+arr[i]<=mid){
                temp+=arr[i];
            }
            else{
                partitions++;
                if(partitions>k || arr[i]>mid){
                    return false;
                }
                temp=arr[i];
            }
            i++;
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        long long int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        long long int start=0,end=sum;
        long long int ans=-1;
        while(start<=end){
            long long int mid = (start+end)/2;
            if(is_possible(arr,mid,n,k)){
                ans = mid;
                end = mid-1;
            }
            else{
                start=mid+1;
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
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends