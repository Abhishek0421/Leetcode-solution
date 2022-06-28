// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool is_pos(int k,int n,int target,int currsum,int a[],vector<int> &visi){
        if(k==1){
            return true;
        }
        if(currsum==target){
            return is_pos(k-1,n,target,0,a,visi);
        }
        
        for(int i=0;i<n;i++){
            if(!visi[i]){
                visi[i]=1;
                if(is_pos(k,n,target,currsum+a[i],a,visi)){
                    return true;
                }
                visi[i]=0;
            }
        }
        return false;
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         int sum=0;
         for(int i=0;i<n;i++){
             sum+=a[i];
         }
         if(sum%k==0){
             vector<int> visi(n,0);
             return is_pos(k,n,sum/k,0,a,visi);
         }
         return 0;
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
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends