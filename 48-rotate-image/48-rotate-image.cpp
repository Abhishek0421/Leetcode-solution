class Solution {
public:
    void transpose(vector<vector<int>> &matrix){
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i<=j){
                    continue;
                }
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    void reverse(vector<vector<int>> &matrix){
        int n = matrix.size();
        for(int i=0;i<n;i++){
            int start=0,end = n-1;
            while(start<=end){
                swap(matrix[i][start],matrix[i][end]);
                start++;
                end--;
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverse(matrix);
    }
};