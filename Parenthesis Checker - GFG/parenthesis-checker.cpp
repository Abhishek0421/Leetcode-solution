// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        int n = x.length();
        stack<char> st;
        if(x[0]==')'||x[0]==']'||x[0]=='}'||x[n-1]=='{'||x[n-1]=='['||x[n-1]=='('){
            return false;
        }
        for(int i=0;i<n;i++){
            if(x[i]=='{'||x[i]=='['||x[i]=='('){
                st.push(x[i]);
            }
            else if(x[i]==']'){
                if(st.size()==0){
                    return false;
                }
                else{
                    if(st.top()=='['){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
            else if(x[i]==')'){
                if(st.size()==0){
                    return false;
                }
                else{
                    if(st.top()=='('){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
            else if(x[i]=='}'){
                if(st.size()==0){
                    return false;
                }
                else{
                    if(st.top()=='{'){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
            
        }
        if(st.size()!=0){
            return false;
        }
        return true;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends