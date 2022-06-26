// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int i=0;
        int j=i+1;
        while(i<n && j<n){
            if(a[j]<a[i]){
                swap(a[i],a[j]);
                if(a[i]==0){
                    i++;
                }
                j++;
            }
            else{
                if(a[i]==0){
                    i++;
                }
                j++;
            }
        }
        j = i+1;
        while(i<n && j<n){
            if(a[j]<a[i]){
                swap(a[i],a[j]);
                if(a[i]==1){
                    i++;
                }
                j++;
            }
            else{
                if(a[i]==1){
                    i++;
                }
                j++;
            }
        }
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends