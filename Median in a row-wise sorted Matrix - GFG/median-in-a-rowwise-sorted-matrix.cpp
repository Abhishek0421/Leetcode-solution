// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int cnt(vector<int> &v,int val){
        int len = 0;
        int low = 0;
        int high = v.size()-1;
        while(low<=high){
            int mid = (high+low)/2;
            if(v[mid]<val){
                len = mid+1;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return len;
    }
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here  
        int ans = 0;
        int high = 2001;
        int low = 0;
        while(low<=high){
            int mid = (high+low)/2;
            int count=0;
            for(int i=0;i<r;i++){
                count += cnt(matrix[i],mid);
            }
            if(count <= (r*c)/2){
                low = mid+1;
                ans = mid;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends