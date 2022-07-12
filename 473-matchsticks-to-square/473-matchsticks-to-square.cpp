class Solution {
public:
    bool solve(int target,int i,int n,vector<int> &m,vector<int> &sides){
        if(i==n){
            return true;
        }
        for(int j=0;j<4;j++){
            if(sides[j]+m[i]<=target){
                sides[j] += m[i];
                if(solve(target,i+1,n,m,sides)==true){
                    return true;
                }
                sides[j] -= m[i];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        
        vector<int> visi(n,0);
        int sum =0;
        for(auto x:matchsticks){
            sum+=x;
        }
        if(sum%4!=0){
            return false;
        }
        sum = sum/4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> sides(4,0);
        return solve(sum,0,n,matchsticks,sides);
    }
};