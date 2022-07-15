class Solution {
public:
    int maxSatisfaction(vector<int>& S) {
        sort(S.begin(),S.end(),greater<int>());
        int sum=0;
        vector<int> P;
        for(int i=0;i<S.size();i++){
            sum+=S[i];
            if(sum<0) break;
            P.push_back(S[i]);
        }
        reverse(P.begin(),P.end());
        sum=0;
        for(int i=0;i<P.size();i++){
            sum+=(i+1)*P[i];
        }
        return sum;
    }
};