// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool is_safe(int i,int j,vector<vector<int>> &visi){
        int a = i,b=j;
        while(i>=0 && j>=0){
            if(visi[i][j]==1){
                return false;
            }
            i--;
            j--;
        }
        i=a,j=b;
        while(i>=0 && j<visi.size()){
            if(visi[i][j]==1){
                return false;
            }
            i--;
            j++;
        }
        i=a,j=b;
        while(i>=0){
            if(visi[i][j]==1){
                return false;
            }
            i--;
        }
        return true;
    }
    vector<vector<int>> res;
    void solve(int n,int i,vector<vector<int>> &visi,vector<int> &v){
        if(i==n){
            res.push_back(v);
            return;
        }
        for(int j=0;j<n;j++){
            if(is_safe(i,j,visi)){
                visi[i][j]=1;
                v.push_back(j+1);
                solve(n,i+1,visi,v);
                v.pop_back();
                visi[i][j]=0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> visi(n,vector<int> (n,0));
        vector<int> v;
        solve(n,0,visi,v);
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends