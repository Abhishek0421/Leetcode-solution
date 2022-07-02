class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int mod = 1000000007;
        long long mv = verticalCuts[0],mh = horizontalCuts[0];
        for(int i=1;i<horizontalCuts.size();i++){
            mh = max((int)mh , (horizontalCuts[i]-horizontalCuts[i-1]));
           // mh%=mod;
        }
        for(int j=1;j<verticalCuts.size();j++){
            mv = max((int)mv,(verticalCuts[j]-verticalCuts[j-1]));
           // mv%=mod;
        }
        long long ans =  (mv*mh)%mod;
        return (int)ans%mod;
    }
};