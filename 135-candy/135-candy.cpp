class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        vector<int> lefts(n, 1);
        vector<int> rights(n, 1);
        
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i-1]) {
                lefts[i] = lefts[i-1] + 1;
            }
        }
        
        for(int i = n - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1]) {
                rights[i] = rights[i+1] + 1;
            }
        }
        
        int ans = 0;
        
        for(int i = 0 ; i < n; i++) {
            ans += max(lefts[i], rights[i]);
        }
        
        return ans;
        
    }
};