// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        sort(arr,arr+n,greater<int>());
        
        int i=0;
        string a="",b="",s="";
        for(int i=0;i<n;i++){
            if(i%2==0){
                a = a + to_string(arr[i]);
            }
            else{
                b = b + to_string(arr[i]);
            }
           // i++;
        }
        
        int carry=0;
        for(int i=0;i<n;i++){
            int x=0;
            int y=0;
            if(i<a.size()){
                x = a[i]-'0';
            }
            if(i<b.size()){
                y = b[i]-'0';
            }
            if(x==0 && y==0 && carry==0){
                break;
            }
            int sum = x+y+carry;
            int t = sum%10;
            s = s + to_string(t);
            carry = sum/10;
        }
        if(carry!=0){
            s = s + to_string(carry);
        }
        reverse(s.begin(),s.end());
        return s;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends