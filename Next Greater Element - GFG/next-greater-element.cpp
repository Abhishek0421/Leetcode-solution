//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long> st;
        vector<long long> v;
        st.push(n-1);
        v.push_back(-1);
        int i = n-2;
        while(!st.empty() && i>=0){
            if(arr[st.top()] > arr[i]){
                v.push_back(arr[st.top()]);
                st.push(i);
                i--;
            }
            else{
                st.pop();
                if(st.empty()){
                    v.push_back(-1);
                    st.push(i);
                    i--;
                }
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends