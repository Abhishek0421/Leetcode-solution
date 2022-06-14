class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int len = 0;
        int n = s.length();
        map<int,int> mp;
        while(i<n && j<n){
            if(mp[s[j]]==0){
                mp[s[j]]++;
                len = max(len , j-i+1);
                j++;
            }
            else{
                mp[s[i]]--;
                i++;
            }
        }
        return len;
    }
};