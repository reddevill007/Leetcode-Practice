class Solution {
    void solve(int idx, int sum, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& ans, int target) {
        if (sum > target) return;  
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        if(idx >= candidates.size()) {
            return;
        }

        temp.push_back(candidates[idx]);
        solve(idx, sum + candidates[idx], candidates, temp, ans, target);

        temp.pop_back();
        solve(idx + 1, sum, candidates, temp, ans, target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, 0, candidates, temp, ans, target);
        return ans;
    }
};