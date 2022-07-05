class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
         int n = s.length(), wl = words[0].length(), ws = words.size();
        
        int totalsize = ws*wl;  
        
        vector<int> res;
        
        unordered_map<string, int> mp;
        
        for(auto i : words)              
            mp[i]++;

        int i=0;
        
        while(i<=n-totalsize)
        {
            unordered_map<string,int> umap;  
            
            for(int j=i; j<i+totalsize; j+=wl)
            { 
               
                string w = s.substr(j,wl);
                
                umap[w]++;
                
            }
            
            if(umap==mp) 
                res.push_back(i);  
            i++;
        }
        return res;
    }
};