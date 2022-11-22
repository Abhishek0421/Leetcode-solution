// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<int> r;
        vector<int> l;
        
        stack<pair<long long,long long>> st;
        st.push(make_pair(arr[0],0));
        r.push_back(-1);
        int i = 1;
        while(!st.empty() && i<n){
            long long curr = arr[i];
            if(st.top().first < curr){
                r.push_back(st.top().second);
                st.push(make_pair(curr,i));
                i++;
            }
            else{
                st.pop();
                if(st.empty()){
                    r.push_back(-1);
                    st.push(make_pair(curr,i));
                    i++;
                }
            }
        }
        stack<pair<long long,long long>> s;
        s.push(make_pair(arr[n-1],n-1));
        l.push_back(n);
        int j = n-2;
        while(!s.empty() && j>=0){
            long long curr = arr[j];
            if(s.top().first <  curr){
                l.push_back(s.top().second);
                s.push(make_pair(curr,j));
                j--;
            }
            else{
                s.pop();
                if(s.empty()){
                    l.push_back(n);
                    s.push(make_pair(curr,j));
                    j--;
                }
            }
        }
        reverse(l.begin(),l.end());
        long long ans=0;
        for(int i=0;i<n;i++){
            ans = max(ans , ((l[i]-r[i])- 1)*arr[i]);
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends