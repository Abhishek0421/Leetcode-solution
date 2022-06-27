class Solution {
public:
    unordered_set<string> st,visi;
    int is_bal(string s){
        int n = s.length();
        stack<char> t;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                t.push(s[i]);
            }
            else if(s[i]==')'){
                if(!t.empty() && t.top()=='('){
                    t.pop();
                }
                else{
                    t.push(s[i]);
                }
            }
        }
        return t.size();
    }
    void solve(string s,int c){
        if(visi.find(s)!=visi.end()){
            return;
        }
        visi.insert(s);
        if(c==0){
            st.insert(s);
            return;
        }
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]==')'){
                solve(s.substr(0,i)+s.substr(i+1),c-1);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int mn_r = is_bal(s);
        solve(s,mn_r);
        vector<string> res;
        for(auto x:st){
            if(is_bal(x)==0){
                res.push_back(x);
            }
        }
        return res;
    }
};