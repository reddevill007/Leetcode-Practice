class Solution {
    void solve(int idx, vector<int>& nums, vector<int>& temp, vector<vector<int>> &ans) {
        // base case
        if(idx >= nums.size()) {
            ans.push_back(temp);
            return;
        }

        // take
        temp.push_back(nums[idx]);
        solve(idx + 1, nums, temp, ans);

        // not take
        temp.pop_back();
        solve(idx + 1, nums, temp, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, nums, temp, ans);

        return ans;
    }
};