class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n);
        left[0] = height[0];
        vector<int> right(n);
        right[n-1] = height[n-1];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],height[i]);
            right[n-1-i] = max(right[n-i],height[n-1-i]);
        }
        int ans =0;
        for(int i=0;i<n;i++){
            int m = min(left[i],right[i]);
            ans = ans + m-height[i];
        }
        return ans;
    }
};