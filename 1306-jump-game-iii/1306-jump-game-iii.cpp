class Solution {
public:
    bool solve(vector<int> &arr,int start,vector<int> &visi){
        if(arr[start]==0){
            return true;
        }
        
        bool left = false,right = false;
        if(start-arr[start]>=0){
            if(!visi[start-arr[start]]){
                visi[start-arr[start]]=1;
                left = solve(arr,start-arr[start],visi);
            }
        }
        if(start+arr[start]<=arr.size()-1){
            if(!visi[start+arr[start]]){
                visi[start+arr[start]]=1;
                right = solve(arr,start+arr[start],visi);
            }
        }
        return left || right;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> visi(arr.size(),0);
        return solve(arr,start,visi);
    }
};