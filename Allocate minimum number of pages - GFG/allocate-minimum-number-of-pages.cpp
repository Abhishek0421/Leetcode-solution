// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool is_possible(int mid,int arr[],int m,int n){
        int partition=1;
        int i=0;
        int temp=0;
        while(i<n){
            if(temp+arr[i]<=mid){
                temp+=arr[i];
                i++;
            }
            else{
                partition++;
                if(partition>m || arr[i]>mid){
                    return false;
                }
                temp=arr[i];
                i++;
            }
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=A[i];
        }
        int start = 0,end=sum;
        int ans = -1;
        while(start<=end){
            int mid = (start+end)/2;
            if(is_possible(mid,A,M,N)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends