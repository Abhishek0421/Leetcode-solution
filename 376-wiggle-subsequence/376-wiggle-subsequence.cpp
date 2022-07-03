class Solution {
public:
    int dp[1001][1001][3];
    int solve(vector<int> &num,int i,int j,int c){
        if(j==num.size() || i==num.size()){
            return 0;
        }
        if(dp[i][j][c]!=-1){
            return dp[i][j][c];
        }
        int ans = 0;
        if(c==0){
            if(num[i]-num[j]<0){
                ans =max(1+solve(num,j,j+1,2),solve(num,i,j+1,0));
            }
            else if(num[i]-num[j]>0){
                ans =max(1+solve(num,j,j+1,1),solve(num,i,j+1,0));
            }
            else{
                //ans = solve(num,i,j+1,0);
                ans = max(solve(num,i,j+1,0),solve(num,i+1,j+1,0));
            }
        }
        else if(c==2){
            if(num[i]-num[j]>0){
                ans = max(1+solve(num,j,j+1,1),solve(num,i,j+1,2));
            }
            else{
                //ans = solve(num,i,j+1,2);
                ans = max(solve(num,i,j+1,2),solve(num,i+1,j+1,2));
            }
        }
        else{
            if(num[i]-num[j]<0){
                ans = max(1+solve(num,j,j+1,2),solve(num,i,j+1,1));
            }
            else{
                //ans = solve(num,i,j+1,1);
                ans = max(solve(num,i,j+1,1),solve(num,i+1,j+1,1));
            }
        }
        return dp[i][j][c]=ans;
    }
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        if(n==1){
            return 1;
        }
        return solve(nums,0,1,0)+1;
    }
};