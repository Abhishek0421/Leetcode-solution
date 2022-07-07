class Solution {
public:
int n=7;
int set_row_zero(vector<vector<int>> & matrix, int r, int c ){
for(int i=0;i<c;i++)
if(matrix[r][i]!=0)
matrix[r][i]=n;

    return 0;
}

int set_clm_zero(vector<vector<int>> & matrix, int r, int c ){
    for(int i=0;i<r;i++)
        if(matrix[i][c]!=0)
        matrix[i][c]=n;
    return 0;
}
void setZeroes(vector<vector<int>>& matrix) {
    int r=matrix.size();
    int c=matrix[0].size();
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==n)
                n++;
        }
    }
    n=54327;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
          if(matrix[i][j]==0){
              set_row_zero(matrix,i,c);
          }  
        }
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            if(matrix[j][i]==0){
                set_clm_zero(matrix,r,i);
            }
        }
    }
    for(int i=0;i<matrix.size();i++)
        for(int j=0;j<matrix[0].size();j++)
            if(matrix[i][j]==n)
                matrix[i][j]=0;
}
};