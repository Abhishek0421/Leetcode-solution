// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int prefixStrings(int N)
	{
	    // Your code goes here
	  

    uint64_t t[N+1];
    t[0]=1;
    t[1]=1;
    int mod=1000000007;
    for(int i=2;i<=N;i++){
        t[i]=0;
        for(int j=1;j<=i;j++){
            t[i]=(t[i]% mod)+((t[j-1]% mod)*(t[i-j]% mod)) % mod;
        }
    }
    return t[N]%mod;



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

       

        Solution ob;
        cout << ob.prefixStrings(n);
	    cout << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends