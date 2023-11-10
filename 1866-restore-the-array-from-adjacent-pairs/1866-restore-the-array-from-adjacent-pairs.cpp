class Solution {
    vector<int> res;

    void dfs(int startPoint, int prev, unordered_map<int, vector<int>> &adj) {
        res.push_back(startPoint);

        for(auto it: adj[startPoint]) {
            if(prev != it) {
                dfs(it, startPoint, adj);
            }
        }
    }
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;

        for(vector<int> &it: adjacentPairs) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int startPoint = -1;

        for(auto &it: adj) {
            if(it.second.size() == 1) {
                startPoint = it.first;
                break;
            }
        }

        dfs(startPoint, INT_MIN, adj);

        return res;
    }
};