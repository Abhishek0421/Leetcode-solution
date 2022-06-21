// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	vector<vector<int>> vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/
vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
//Your code here
  // set<string> s;
   map<string,int> mp;
   vector<vector<int>> v;
   for(int i=0;i<row;i++){
       string t="";
       for(int j=0;j<col;j++){
           t += to_string(M[i][j]);
       }
       mp[t]++;
       if(mp[t]==1){
           vector<int> temp;
           for(int i=0;i<t.length();i++){
              temp.push_back(t[i]-'0');
           }
           v.push_back(temp);
       }
   }
   return v;
}