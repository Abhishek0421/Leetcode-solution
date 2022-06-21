// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
   vector<vector<string>> displayContacts(int n, string contact[], string s)
   {
       string temp;
       map<string,int> cont;
       vector<vector<string>>  out(s.size(),vector<string>(1,"0"));
       int flag=0;
       
       
       for(int j=0;j<n;j++)
       {
           
           cont[contact[j]];
           
       }
       
       
       for(int i=0;i<s.size();i++)
       {
           temp.clear();
           temp=s.substr(0,1+i);
           flag=0;
           out[i].clear();
           for(auto j : cont)
           {
               
               if(temp.compare((j.first).substr(0,1+i))==0)
               {
                  
                  out[i].push_back((j.first));
                  flag=1;
               }
               
           }
           
           if(flag==0)
           {
               out[i].push_back("0");
           }
           
       }
       
       return out;
   }

 
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends