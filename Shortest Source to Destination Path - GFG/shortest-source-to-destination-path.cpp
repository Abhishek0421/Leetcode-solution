// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        vector<int> mi={0,0,-1,1};
        vector<int> mj={-1,1,0,0};
        if(A[0][0]==0){
            return -1;
        }
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> visi(N,vector<int> (M,0));
        q.push({0,{0,0}});
        int ans =INT_MAX;
        while(!q.empty()){
            int s = q.size();
            int f=0;
            for(int k=0;k<s;k++){
                auto it = q.front();
                q.pop();
                int d = it.first;
                int i = it.second.first;
                int j = it.second.second;
                if(i == X && j == Y){
                    f=1;
                    ans = d;
                    break;
                }
                for(int l=0;l<4;l++){
                    int x = i+mi[l];
                    int y = j+mj[l];
                    if(x>=0 && y>=0 && x<N && y<M && A[x][y]==1 && visi[x][y]==0){
                        visi[x][y]=1;
                        q.push({d+1,{x,y}});
                    }
                }
            }
            if(f){
                break;
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends