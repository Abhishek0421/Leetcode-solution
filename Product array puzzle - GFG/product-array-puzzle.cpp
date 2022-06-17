// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here 
        vector<long long> pre(n);
        vector<long long> suff(n);
        if(n==1){
            return {1};
        }
        long long a=1,b=1;
        for(int i=0;i<n;i++){
            suff[n-1-i] = a*nums[n-1-i];
            a = a*nums[n-i-1];
            pre[i] = b*nums[i];
            b = b*nums[i];
        }
        vector<long long > res(n);
        for(int i=0;i<n;i++){
            if(i==0){
                res[i]=suff[i+1];
            }
            else if(i==n-1){
                res[i] = pre[i-1];
            }
            else{
                res[i] = pre[i-1]*suff[i+1];
            }
        }
        return res;
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends