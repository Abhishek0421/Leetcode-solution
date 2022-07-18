class Solution {
public:
    void dfs(vector<vector<char>>&board,int row,int col,int m,int n){
        if(row<0 || row>=m || col<0 || col>=n){
            return;
        }
        board[row][col] = 'B';
        if(row-1>=0 && board[row-1][col]=='O'){
            dfs(board,row-1,col,m,n);
        }
        if(col+1<n && board[row][col+1] == 'O'){
            dfs(board,row,col+1,m,n);
        }
        if(row+1<m && board[row+1][col] == 'O'){
            dfs(board,row+1,col,m,n);
        }
        if(col-1>=0 && board[row][col-1] == 'O'){
            dfs(board,row,col-1,m,n);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            if(board[i][0] == 'O'){
                dfs(board,i,0,m,n);
            }
        }
        for(int i=0;i<n;i++){
            if(board[0][i] == 'O'){
                dfs(board,0,i,m,n);
            }
        }
        for(int i=0;i<n;i++){
            if(board[m-1][i] == 'O'){
                dfs(board,m-1,i,m,n);
            }
        }
        for(int i=0;i<m;i++){
            if(board[i][n-1] == 'O'){
                dfs(board,i,n-1,m,n);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == 'B'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};