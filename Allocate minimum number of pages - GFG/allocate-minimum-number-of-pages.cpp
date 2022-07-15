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
    bool is_possible(int a[],int n,int m,int mid){
        int partition = 1;
        int temp = 0;
        int i=0;
        while(i<n){
            if(temp+a[i]<=mid){
                temp+=a[i];
                i++;
            }
            else{
                partition++;
                if(partition > m || a[i]>mid){
                    return false;
                }
                temp = a[i];
                i++;
            }
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        int low = 0;
        int sum =0;
        int ans = 0;
        for(int i=0;i<N;i++){
            sum+=A[i];
        }
        int high = sum;
        while(low<=high){
            int mid = (high+low)/2;
            if(is_possible(A,N,M,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
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