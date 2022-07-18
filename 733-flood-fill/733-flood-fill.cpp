class Solution {
public:
    vector<int> mi={0,0,1,-1};
    vector<int> mj={1,-1,0,0};
    void dfs(int sr,int sc,vector<vector<int>>& image,vector<vector<int>> &visi,int newcol,int col){
        visi[sr][sc]=1;
        image[sr][sc]=newcol;
        for(int k=0;k<4;k++){
            int x = sr+mi[k];
            int y = sc+mj[k];
            if(x>=0 && y>=0 && x<image.size() && y<image[0].size() && image[x][y]==col && visi[x][y] ==0){
                dfs(x,y,image,visi,newcol,col);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> visi(image.size(),vector<int> (image[0].size(),0));
        dfs(sr,sc,image,visi,newColor,image[sr][sc]);
        return image;
    }
};