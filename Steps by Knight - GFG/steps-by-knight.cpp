// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
    {
        queue<pair<int, pair<int, int>>> q;
        
        int vis[N+1][N+1];
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i <= N; i++){
            vis[i][0] = 1;
            vis[0][i] = 1;
        }
        q.push({0, {KnightPos[0], KnightPos[1]}});
        
        int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
        int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
        
        int ans = 1e9;
        
        while(!q.empty()){
            int x = q.front().second.first;
            int y = q.front().second.second;
            int cnt = q.front().first;
            q.pop();
            
            if(TargetPos[0] == x and TargetPos[1] == y){
                return cnt;
            }
            
            for(int k = 0; k < 8; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                if(nx >= 1 and nx <= N and ny >= 1 and ny <= N and vis[nx][ny] == 0){
                    q.push({cnt+1, {nx, ny}});
                    vis[nx][ny] = 1;
                }
            }
            
        }
        return -1;
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends