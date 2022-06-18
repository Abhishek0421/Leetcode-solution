// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    vector<int> mi={0,0,-1,1};
    vector<int> mj={1,-1,0,0};
    bool dfs(vector<vector<int>> &v,int si,int sj,vector<vector<int>> &visi){
        if(v[si][sj]==2){
            return true;
        }
        visi[si][sj]=1;
        for(int i=0;i<4;i++){
            int x = si+mi[i];
            int y = sj+mj[i];
            if(x>=0 && y>=0 && x<v.size() && y<v[0].size() && v[x][y]!=0 && visi[x][y]==0){
                if(dfs(v,x,y,visi)){
                    return true;
                }
            }
        }
        return false;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                vector<vector<int>> visi(n,vector<int> (m,0));
                if(grid[i][j]==1){
                    if(dfs(grid,i,j,visi)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends