class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 1;
        for(int i=0;i<n;i++){
            map<double,int> mp;
            int x1=points[i][0],y1=points[i][1];
            for(int j=i+1;j<n;j++){
                int x2=points[j][0],y2=points[j][1];
                double s=0;
                if(x1-x2==0){
                    mp[1e9]++;
                    ans = max(mp[1e9]+1,ans);
                }
                else{
                    s = (double)(y1-y2)/(x1-x2);
                    mp[s]++;
                    ans = max(mp[s]+1,ans);
                }
                
            }
            //cout<<ans<<" ";
        }
        //cout<<"\n";
        return ans;
    }
};