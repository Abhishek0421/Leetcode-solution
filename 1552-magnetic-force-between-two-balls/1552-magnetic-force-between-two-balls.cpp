class Solution {
public:
    bool is_possible(vector<int> &v,int m,int mid){
        int partitions=1;
        int lastpos = v[0];
        for(int i=1;i<v.size();i++){
            if(v[i]-lastpos >= mid){
                partitions++;
                if(partitions==m){
                    return true;
                }
                lastpos=v[i];
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int start=0;
        int end = position[position.size()-1]-position[0];
        int ans=-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(is_possible(position,m,mid)){
                ans = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
};