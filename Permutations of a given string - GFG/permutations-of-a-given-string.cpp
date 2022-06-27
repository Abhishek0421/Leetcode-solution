// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    set<string> res;
	    void permu(string &s,int i,vector<int> &taken,string t){
	        if(i==s.length()){
	            res.insert(t);
	        }
	        for(int j=0;j<s.length();j++){
	            if(!taken[j]){
	                taken[j]=1;
	                permu(s,i+1,taken,t+s[j]);
	                taken[j]=0;
	            }
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<int> taken(S.length(),0);
		    permu(S,0,taken,"");
		    vector<string> ans(res.begin(),res.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends