class Solution {
public:
    bool check(string &s){
        int n = s.length();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]){
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(int x) {
        if(x<0){
            return false;  
        }
        string s = to_string(x);
        return check(s);
    }
};