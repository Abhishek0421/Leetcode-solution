class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string s = strs[0];
        string t = strs[strs.size()-1];
        int i = 0,j=0;
        int len=0;
        while(i<s.length() && j<t.length()){
            if(s[i]!=t[i]){
                break;
            }
            len++;
            i++;
        }
        return s.substr(0,len);
    }
};