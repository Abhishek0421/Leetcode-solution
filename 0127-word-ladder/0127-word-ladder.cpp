class Solution {
public:
    bool caninsert(string &a,string &b){
        int n=a.length();
        int d=0;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                d++;
            }
        }
        return d==1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> mp;
        wordList.push_back(beginWord);
        for(int i=0;i<wordList.size();i++){
            for(int j=i+1;j<wordList.size();j++){
                if(caninsert(wordList[i],wordList[j])){
                    mp[wordList[i]].push_back(wordList[j]);
                    mp[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        map<string,int> visi;
        queue<pair<string,int>> q;
        
        q.push({beginWord,1});
        while(!q.empty()){
            string s=q.front().first;
            int d=q.front().second;
            q.pop();
            for(auto x:mp[s]){
                if(visi[x]==1)continue;
                if(x==endWord){
                    return d+1;
                }
                q.push({x,d+1});
                visi[x]=1;
            }
        }
        return 0;
    }
};