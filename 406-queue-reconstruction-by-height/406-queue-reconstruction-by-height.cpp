class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        sort(people.begin(), people.end(), [](vector<int> p1, vector<int> p2)
            {if (p1[0] == p2[0]) return p1[1] < p2[1];  return p1[0] > p2[0]; });

        vector<vector<int>> res;

        for (vector<int> p : people)
        {
            auto it = res.begin() + p[1];
            res.insert(it, p);
        }
        
        return res;
        
    }
};