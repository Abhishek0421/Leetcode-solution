// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i=0;
        int j=0;
        int p=0;
        
        vector<int> a(n+m);
        while(i<n && j<m){
            if(arr1[i]>arr2[j]){
                a[p]=arr2[j];
                j++;
                p++;
            }
            else{
                a[p]=arr1[i];
                i++;
                p++;
            }
        }
        if(i<n){
            while(i<n){
                a[p]=arr1[i];
                i++;
                p++;
            }
        }
        else{
            while(j<m){
                a[p]=arr2[j];
                j++;
                p++;
            }
        }
        return a[k-1];
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends