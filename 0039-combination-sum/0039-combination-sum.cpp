class Solution {
    void solve(vector<int> candidates, int target, int ind, vector<vector<int>> &ans, vector<int> &ds) {
        if(ind == candidates.size()) {
            if(target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        if(candidates[ind] <= target) {
            ds.push_back(candidates[ind]);
            solve(candidates, target - candidates[ind], ind, ans, ds);
            ds.pop_back();
        }

        solve(candidates, target, ind + 1, ans, ds);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int ind = 0;

        solve(candidates, target, ind, ans, ds);

        return ans;
    }
};