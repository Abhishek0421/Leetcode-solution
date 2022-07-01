// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue <int> max_heap;
    priority_queue <int , vector<int>,greater<int>> min_heap;
    
    void insertHeap(int &x)
    {
        max_heap.push(x);
        min_heap.push(max_heap.top());
        max_heap.pop();
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(min_heap.size()>max_heap.size())
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        double ans=0;
        if((min_heap.size()+max_heap.size())%2!=0) 
        {
            ans=max_heap.top();
        }
        else
        {    ans=max_heap.top()+min_heap.top();
             ans/=2;
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