class Solution {
    void solve(int num, int lim, int len, vector<vector<int>> &ans, vector<int> &ds) {
        if(num == lim + 1) {
            if(ds.size() == len) {
                ans.push_back(ds);
            }
            return;
        }

        ds.push_back(num);
        solve(num + 1, lim, len, ans, ds);

        ds.pop_back();
        solve(num + 1, lim, len, ans, ds);
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;

        solve(1, n, k, ans, ds);

        return ans;
    }
};