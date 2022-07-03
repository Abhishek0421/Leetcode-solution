// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        map<char,int> mp1,mp2;
    int n = a.length();
    int m = b.length();
    if(n!=m){
        return false;
    }
    for(int i=0;i<n;i++){
        mp1[a[i]]++;
        mp2[b[i]]++;
    }
    for(int i=0;i<m;i++){
        if(mp1[a[i]]!=mp2[a[i]]){
            return false;
        }
    }
    return true;
        
    }

};

// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
  // } Driver Code Ends