// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            pq.push_back({price[i],i+1});
        }
        int count=0;
        sort(pq.begin(),pq.end());
        for(int i=0;i<n;i++){
            auto it = pq[i];
            for(int j=1;j<=it.second;j++){
                if(k-it.first >=0){
                    count++;
                    k-=it.first;
                    //cout<<k<<"\n";
                }
                else{
                    break;
                }
            }
        }
        return count;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends