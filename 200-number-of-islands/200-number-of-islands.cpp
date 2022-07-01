class Solution {
public:
    vector<int> mi={0,0,1,-1};
    vector<int> mj={1,-1,0,0};
    void dfs(int si,int sj,vector<vector<int>> &visi,vector<vector<char>> &grid){
        if(si<0 || sj<0 || si>=grid.size() || sj>=grid[0].size() || grid[si][sj]=='0' || visi[si][sj]==1){
            return;
        }
        
        visi[si][sj]=1;
        for(int i=0;i<4;i++){
            int x = si+mi[i];
            int y = sj+mj[i];
            dfs(x,y,visi,grid);
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        vector<vector<int>> visi(grid.size(),vector<int> (grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && visi[i][j]==0){
                    count++;
                    dfs(i,j,visi,grid);
                }
            }
        }
        return count;
    }
};