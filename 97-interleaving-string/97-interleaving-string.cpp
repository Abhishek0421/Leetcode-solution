class Solution {
public:
    vector<vector<int>> dp;
    bool check(string s1,int i,string s2,int j,string s3){
        if(i+j==s3.size() && i==s1.size() && j==s2.size())return true;
        if(i+j>s3.size())return false;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=(s1[i]==s3[i+j] && check(s1,i+1,s2,j,s3)) || (s2[j]==s3[i+j] && check(s1,i,s2,j+1,s3));
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())return false;
        dp.resize(s1.size()+1,vector<int>(s2.size()+1,-1));
        return check(s1,0,s2,0,s3);
    }
};