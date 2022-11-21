//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    string A, B;
    bool recur(int i, int j) {
    if ((i<0)!=(j<0)) return false;
    return i<0 || A[i]=='*'
        &&(recur(i-1,j-1)||recur(i,j-1)||recur(i-1,j))
        || (A[i]=='?' || A[i]==B[j])&&recur(i-1,j-1);
   }
bool match(string wild, string pattern) {
    A = wild, B = pattern;
    return recur(A.size()-1, B.size()-1);
}
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends