// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int mod = 1e9+7;
    
    long long int findMaxProduct(vector<int>&a, int n){
        int cneg = 0,c0=0;
        int maxneg = INT_MIN;
        long long int ans = 1;
        for(auto x:a){
            if(x<0){
                cneg++;
                maxneg = max(maxneg,x);
            }
            if(x==0){
                c0++;
            }
        }
        if(n==1){
            return a[0];
        }
        if(cneg==1 && c0 == n-1){
            return 0;
        }
        else if(cneg%2==0){
            for(int i=0;i<n;i++){
                if(a[i]!=0){
                    ans = (ans*a[i])%mod;
                    ans= ans%mod;
                }
            }
        }
        else if(cneg%2!=0){
            int f=0;
            for(int i=0;i<n;i++){
                if(a[i]!=0){
                    if(a[i]==maxneg && f==0){
                        f=1;
                        continue;
                    }
                    ans = (ans*a[i])%mod;
                    ans= ans%mod;
                    
                }
            }
        }
        
        return ans%mod;
    }
};



// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends