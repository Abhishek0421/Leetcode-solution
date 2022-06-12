// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        map<int,int> mp;
        int n = s.size();
        if(k>=n){
            return 0;
        }
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(auto x:mp){
            pq.push({x.second,x.first});
        }
        for(int i=0;i<k;i++){
            auto it = pq.top();
            pq.pop();
            pq.push({it.first-1,it.second});
            mp[it.second]--;
        }
        int ans=0;
        for(auto x:mp){
            ans = ans +(x.second*x.second);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends