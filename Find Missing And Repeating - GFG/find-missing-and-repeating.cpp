// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        
        for(int i=0;i<n;){
            if(arr[i]==i+1){
                i++;
            }
            else{
                if(arr[arr[i]-1] == arr[i]){
                    i++;
                }
                else{
                    swap(arr[arr[i]-1],arr[i]);
                }
                
            }
        }
        int rep=0;
        int mis=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1){
                rep = arr[i];
                mis = i+1;
                break;
            }
        }
        int *a = new int[2];
        a[0]=rep;
        a[1]=mis;
        return a;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends