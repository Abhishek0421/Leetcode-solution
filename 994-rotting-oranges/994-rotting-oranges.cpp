class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        int t=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==2) q.push({i,j});
                
         int dx[4] = {0,0,-1,1},dy[4] = {1,-1,0,0};
	    while(!q.empty())
	    {
	        int size = q.size();
	       while(size>0){
	       int x = q.front().first;
	       int y = q.front().second;
	       q.pop();
	       for(int i=0;i<4;i++)
	       {
	           if(x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<m)
	           if(grid[x+dx[i]][y+dy[i]]==1)
	           {
	               grid[x+dx[i]][y+dy[i]]=2;
	               q.push({x+dx[i],y+dy[i]});
	           }
	        }
	       size--;
	    }
	       if(!q.empty()) t++;
	    }
	   for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==1) return -1;
     return t;
    }

};