class Solution {
public:
    vector<int> mi={0,0,1,-1};
    vector<int> mj={1,-1,0,0};
    void dfs(int si,int sj,vector<vector<char>> &grid){
        if(si<0 || sj<0 || si>=grid.size() || sj>=grid[0].size() || grid[si][sj]=='0'){
            return;
        }
        
        grid[si][sj]='0';
        for(int i=0;i<4;i++){
            int x = si+mi[i];
            int y = sj+mj[i];
            dfs(x,y,grid);
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' ){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};