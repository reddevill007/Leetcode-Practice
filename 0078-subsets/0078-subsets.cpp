class Solution {
    void subsets(vector<int>& nums, vector<int>& ds, int ind, int n, vector<vector<int>> &ans) {
        if(ind == n) {
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[ind]);

        subsets(nums, ds, ind + 1, n, ans);

        ds.pop_back();

        subsets(nums, ds, ind + 1, n, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int ind  = 0;
        vector<int> ds = {};
        vector<vector<int>> ans;

        subsets(nums, ds, ind, n, ans);

        return ans;
    }
};