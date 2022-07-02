class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int ans = 0;
        for(auto x:boxTypes){
            if(x[0]<truckSize){
                ans += (x[0]*x[1]);
                truckSize-=x[0];
            }
            else{
                ans += truckSize*x[1];
                break;
            }
        }
        return ans;
    }
};