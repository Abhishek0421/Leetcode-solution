class Solution {
public:
    bool match(string s,string t){
        int idx=0;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]==t[idx]) idx++;
            if(idx==t.length()) return true;
        }
        return false;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string,int> v;
        int ans=0;
        for(auto i:words){
            v[i]++;
        }
        for(auto i:v){
            if(match(s,i.first)){
                ans = ans + i.second;
            }
        }
        return ans;
    }
};