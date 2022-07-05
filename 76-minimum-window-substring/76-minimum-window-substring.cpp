class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        
        unordered_map<char,int> mpp;
        for(auto it:t){
            mpp[it]++;
        }
        
        int count=mpp.size();
        int i=0,j=0;
        string ans="";
        int len=INT_MAX;
        
        while(j<n){
            if(mpp.find(s[j])!=mpp.end()){
                mpp[s[j]]--;
                if(mpp[s[j]]==0){
                    count--;
                }
            }
            
            while(count==0){
                if(len>j-i+1){
                    len=j-i+1;
                    ans=s.substr(i,len);
                }
                if(mpp.find(s[i])!=mpp.end()){
                    mpp[s[i]]++;
                    if(mpp[s[i]]==1)count++;
                }
                i++;
            }
            j++;
        }
        return ans;        
    }
};