class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;

        int n=s.size();
        int m=t.size();
        unordered_map<char , char> mp1,mp2;
        for(int i=0;i<n;i++)
        {
            if(mp1.find(s[i])==mp1.end() && mp2.find(t[i])==mp2.end())
            {
              //  mp.(s[i]);
                mp1[s[i]]=t[i];
                mp2[t[i]]=s[i];
            }
            else
            {
                if(mp1[s[i]]!=t[i] || mp2[t[i]]!=s[i]) return false;
            }
        }
        return true;
    }
};