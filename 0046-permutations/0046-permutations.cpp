class Solution {
    void solve(int ind, vector<int> nums, vector<vector<int>> &ans, vector<int> &ds, vector<bool> &freq) {
        if(ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(!freq[i]) {
                freq[i] = true;

                ds.push_back(nums[i]);
                solve(i + 1, nums, ans, ds, freq);
                ds.pop_back();
                freq[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> freq(nums.size(), false);

        solve(0, nums, ans, ds, freq);

        return ans;
    }
};