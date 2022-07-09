class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
    
    vector<int> dp(n,0);
    
    dp[0]=nums[0];
    
    priority_queue<pair<int,int>> pq;
    
    pq.push({dp[0],0});
    
    for(int i=1;i<n;i++){
        
        while(i-pq.top().second>k){
            pq.pop();
        }
        
        int smallans=pq.top().first;      
        dp[i]=smallans+nums[i];
        pq.push({dp[i],i});
                  
    }
    
    return dp[n-1];
}
    
};