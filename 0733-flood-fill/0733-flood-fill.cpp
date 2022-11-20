class Solution {
public:
    vector<int> mi={1,-1,0,0};
    vector<int> mj={0,0,1,-1};
    void dfs(vector<vector<int>> &m,int i,int j,int scol,int color,vector<vector<int>> &visi){
        if(i>=m.size()||j>=m[0].size()||i<0 || j<0  || m[i][j] == color || m[i][j] != scol){
            return;
        }
        visi[i][j]=1;
        m[i][j]=color;
        for(int k=0;k<4;k++){
            int x = i+mi[k];
            int y = j+mj[k];
            dfs(m,x,y,scol,color,visi);
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> visi(image.size(),vector<int> (image[0].size(),0));
        int scol = image[sr][sc];
        dfs(image,sr,sc,scol,color,visi);
        return image;
    }
};