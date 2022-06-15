// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        // Code Here
        map<char,int> mp,visi;
        int n = a.length();
        for(int i=0;i<n;i++){
            mp[a[i]];
        }
        vector<char> v;
        for(auto x:mp){
           // cout<<x.first<<"\n";
            v.push_back(x.first);
        }
        //mp.clear();
        int j=0;
        pair<char,char> p;
        for(int i=0;i<n;i++){
            if(j>v.size()){
                break;
            }
            if(a[i]==v[j]){
                visi[a[i]]=1;
                j++;
            }
            else{
                if(visi[a[i]]!=1){
                  //  cout<<a[i]<<" "<<v[i]<<"\n";
                    p = {a[i],v[j]};
                    break;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(a[i]==p.first){
                a[i] = p.second;
            }
            else{
                if(a[i]==p.second){
                    a[i] = p.first;
                }
            }
        }
        return a;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends