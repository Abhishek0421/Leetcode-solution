// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int,vector<int>,greater<int>> p2;
    priority_queue<int> p1;
    void insertHeap(int &x)
    {
        if(p1.empty() || p1.top()>=x){
            p1.push(x);
        }
        else{
            p2.push(x);
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        int diff = p1.size()-p2.size();
        if(abs(diff)>1){
            if(p1.size()>p2.size()){
                p2.push(p1.top());
                p1.pop();
            }
            else{
                p1.push(p2.top());
                p2.pop();
            }
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        int ans=0;
        if(p1.size()==0 && p2.size()==0){
            return -1;
        }
        if(p1.size()==p2.size()){
             ans = ((double)p1.top()+p2.top())/2;
           // return ans;
        }
        else {
            if(p1.size()>p2.size()){
                ans = p1.top();
            }
            else{
                ans = p2.top();
            }
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends