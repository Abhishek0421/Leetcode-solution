class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> dp(numRows,0);
        vector<vector<int>> v;
        v.push_back({1});
        dp[0]=1;
        for(int i=1;i<numRows;i++){
            vector<int> temp;
            for(int j=numRows-2;j>=0;j--){
                dp[j+1] = dp[j]+dp[j+1];
                if(dp[j+1]==0) continue;
                temp.push_back(dp[j+1]);
            }
            temp.push_back(1);
            reverse(temp.begin(),temp.end());
            v.push_back(temp);
        }
        return v;
    }
};