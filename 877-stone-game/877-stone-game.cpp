class Solution {
public:
    int Amax(int i,int j,vector<int>& piles,unordered_map<string,int> &memo)
    {
        string pos = to_string(i)+','+to_string(j);
        if(memo.count(pos))
            return memo[pos];
        if(i>j)
            return 0;
        if(i==j)
            return piles[i];
        int f1 = piles[i]+min(Amax(i+2,j,piles,memo),Amax(i+1,j-1,piles,memo));
        int f2 = piles[j]+min(Amax(i+1,j-1,piles,memo),Amax(i,j-2,piles,memo));
        
        memo[pos] = max(f1,f2);
        return memo[pos];
    }
    bool stoneGame(vector<int>& piles) {
        int total = 0;
        unordered_map<string,int> memo;
        for(auto p:piles)
        {
            total+=p;
        }
        int a = Amax(0,piles.size()-1,piles,memo);
        int b = total-a;
        if(a>b)
            return true;
        else
            return false;
    }
};