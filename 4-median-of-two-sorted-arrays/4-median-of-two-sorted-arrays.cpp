class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),m=nums2.size();
        int j=0,i=0;
        vector<int> v;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }
            else{
                v.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n){
            v.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            v.push_back(nums2[j]);
            j++;
        }
        if((n+m)%2==0){
            return (double)(v[(n+m)/2]+v[((n+m)/2)-1])/2;
        }
        return (double)v[(n+m)/2];
    }
};