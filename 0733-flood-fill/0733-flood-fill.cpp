class Solution {
public:
    vector<int> mi={1,-1,0,0};
    vector<int> mj={0,0,1,-1};
    void dfs(vector<vector<int>> &m,int i,int j,int scol,int color){
        if(i>=m.size()||j>=m[0].size()||i<0 || j<0  || m[i][j] == color || m[i][j] != scol){
            return;
        }
        m[i][j]=color;
        for(int k=0;k<4;k++){
            int x = i+mi[k];
            int y = j+mj[k];
            dfs(m,x,y,scol,color);
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int scol = image[sr][sc];
        dfs(image,sr,sc,scol,color);
        return image;
    }
};