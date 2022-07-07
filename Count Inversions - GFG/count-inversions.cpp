// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[],long long temp[],int start,int mid,int end){
        long long int count=0;
        int i = start;
        int j = mid;
        int k = start;
        while(i<=mid-1 && j<=end){
            if(arr[i] <= arr[j]){
               temp[k++] = arr[i++];
            }
            else
            {
               temp[k++] = arr[j++];
               count = count + (mid - i);
            }
        }
        while(i <= mid - 1)
           temp[k++] = arr[i++];

        while(j <= end)
           temp[k++] = arr[j++];

        for(i = start ; i <= end ; i++)
           arr[i] = temp[i];
    
        return count;
    }
    long long int mergesort(long long arr[],long long temp[],int start,int end){
        long long int mid,count=0;
        if(start<end){
            mid = (start+end)/2;
            count += mergesort(arr,temp,start,mid);
            count += mergesort(arr,temp,mid+1,end);
            
            count += merge(arr,temp,start,mid+1,end);
        }
        return count;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N+1];
        return mergesort(arr,temp,0,N-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends