class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        int res = INT_MAX;
        while(low<=high){
            int c = 0;
            int mid = low + (high-low)/2;
            
            for(int i=0;i<n;i++){
                c+=(upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin());
            }
            
            if(c<k){
                low = mid+1;
            }else{
                res = mid;
                high = mid-1;
            }
        }
        
        if(res==INT_MAX) return -1;
        else return res;
    }
};