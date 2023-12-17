class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int limit = n*n;

        unordered_set<int> el_count;
        vector<int> ans(2, -1);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!el_count.insert(grid[i][j]).second) {
                    ans[0] = grid[i][j];
                }
                el_count.insert(grid[i][j]);
            }
        }

        for(int i = 1; i <= limit; i++) {
            if(!el_count.insert(i).second) {
                continue;
            } else {
                ans[1] = i;
            }
        }

        return ans;
    }
};