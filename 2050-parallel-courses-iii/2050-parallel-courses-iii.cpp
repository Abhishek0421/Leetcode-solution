class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> adj[n];
        vector<int> indegree(n, 0), completeTime(n, 0);
        for (auto rel : relations) {
            indegree[rel[1] - 1]++;
            adj[rel[0] - 1].push_back(rel[1] - 1);
        }
        queue<pair<int,int>> q;
		
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push({i, 0});
        }

        while (!q.empty()) {
            int src = q.front().first;
            int comptime = q.front().second;
            q.pop();

            int timeNeeded = time[src] + comptime;
            completeTime[src] = timeNeeded;

            for (auto nbr : adj[src]) {
                indegree[nbr]--;

                completeTime[nbr] = max(completeTime[nbr], timeNeeded);
                if (indegree[nbr] == 0) q.push({nbr,completeTime[nbr]});
            }
        }

        int ans = 0;
        for (auto time : completeTime) ans = max(ans, time);
        return ans;
    }
};