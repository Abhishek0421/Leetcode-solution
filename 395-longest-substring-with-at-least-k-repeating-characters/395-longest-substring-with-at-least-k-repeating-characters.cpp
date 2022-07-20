class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if(n<k || n==0){
            return 0;
        }
        unordered_map<char,int> mp;
        int s1,s2;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp[s[i]]<k){
                s1 = longestSubstring(s.substr(0,i),k);
                s2 = longestSubstring(s.substr(i+1),k);
                break;
            }
            if(i==n-1){
                return n;
            }
        }
        return max(s1,s2);
    }
};