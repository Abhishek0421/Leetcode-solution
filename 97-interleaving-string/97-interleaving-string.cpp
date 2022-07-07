class Solution {
public:
    bool solve(int i,int j,int k,string &s1,string &s2,string &s3,vector<vector<vector<int>>> &dp){
        if(i==s1.length() && j==s2.length() && k==s3.length()){
            return true;
        }
        if(i==s1.length() && j!=s2.length()){
            while(j<s2.length() && k<s3.length()){
                if(s2[j]!=s3[k]){
                    //cout<<1<<endl;
                    return false;
                }
                j++;
                k++;
            }
            return true;
        }
        if(i!=s1.length() && j==s2.length()){
            while(i<s1.length() && k<s3.length()){
                if(s1[i]!=s3[k]){
                    //cout<<2<<endl;
                    return false;
                }
                i++;
                k++;
            }
            return true;
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        //cout<<i<<" "<<j<<" "<<k<<"\n";
        if(s1[i]==s3[k] && s2[j]==s3[k]){
            return dp[i][j][k] = solve(i+1,j,k+1,s1,s2,s3,dp) || solve(i,j+1,k+1,s1,s2,s3,dp);
        }
        else if(s1[i]==s3[k]){
           // cout<<"s1"<<"\n";
            return dp[i][j][k] = solve(i+1,j,k+1,s1,s2,s3,dp);
        }
        else if(s2[j]==s3[k]){
            //cout<<"s2"<<endl;
            return dp[i][j][k] = solve(i,j+1,k+1,s1,s2,s3,dp);
        }
        //cout<<3<<endl;
        return dp[i][j][k] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()){
            return false;
        }
        vector<vector<vector<int>>> dp(s1.length()+1,vector<vector<int>> (s2.length()+1,vector<int> (s3.length()+1,-1)));
        return solve(0,0,0,s1,s2,s3,dp);
    }
};