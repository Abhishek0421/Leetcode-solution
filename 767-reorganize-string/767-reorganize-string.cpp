class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        priority_queue<pair<int,int>> pq;
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(auto x:mp){
            pq.push({x.second,x.first});
        }
        string res="";
        while(pq.size()>1){
            auto it1 = pq.top();
            pq.pop();
            auto it2 = pq.top();
            pq.pop();
            res+=it1.second;
            res+=it2.second;
            
            it1.first-=1;
            it2.first-=1;
            
            if(it1.first>0){
                pq.push(it1);
            }
            if(it2.first>0){
                pq.push(it2);
            }
        }
        if(!pq.empty()){
            if(pq.top().first>1){
                return "";
            }
            else{
                res+=pq.top().second;
            }
        }
        return res;
    }
};