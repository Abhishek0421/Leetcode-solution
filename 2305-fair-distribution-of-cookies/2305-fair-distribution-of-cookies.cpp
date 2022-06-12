class Solution {
public:
    int ans = INT_MAX;
    void solve(int k,vector<int> &a,int i,int n,vector<int> &c){
        if(i==n){
            ans = min(ans,*max_element(c.begin(),c.end()));
            return;
        }
        for(int j=0;j<k;j++){
            c[j]+=a[i];
            solve(k,a,i+1,n,c);
            c[j]-=a[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> c(k,0);
        solve(k,cookies,0,cookies.size(),c);
        return ans;
    }
};