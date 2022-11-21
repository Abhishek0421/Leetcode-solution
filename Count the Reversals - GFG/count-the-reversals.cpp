// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    // your code here
    int ans =0;
    int n = s.size();
    stack<int> st;
    for(int i=0;i<n;i++){
        if(i==0){
            if(s[i]=='}'){
               // ans++;
                st.push('}');
            }
            else{
                st.push('{');
            }
        }
        else {
            if(s[i]=='}'){
                if(!st.empty() && st.top()=='{'){
                    st.pop();
                }
                else{
                    st.push('}');
                }
            }
            else{
                st.push('{');
            }
        }
    }
    int cu=0;
    int cd=0;
    while(!st.empty()){
        if(st.top()=='{'){
            cu++;
        }
        else{
            cd++;
        }
        st.pop();
    }
    if(cu%2==0 && cd%2==0){
        return (cu/2) + (cd/2);
    }
    else if(cu%2!=0 && cd%2!=0){
        return 2 + (cu/2) + (cd/2);
    }
    return -1;
}