class Solution {
    int dp[2501][2501];

    int solve(int prev_idx, int curr_idx, vector<int> &nums) {
        if(curr_idx == nums.size()) {
            return 0;
        }

        if(prev_idx != -1 && dp[prev_idx][curr_idx] != -1) {
            return dp[prev_idx][curr_idx];
        }

        int take = 0;

        if(prev_idx == -1 || nums[prev_idx] < nums[curr_idx]) {
            take = 1 + solve(curr_idx, curr_idx + 1, nums);
        }

        int skip = solve(prev_idx, curr_idx + 1, nums);

        if(prev_idx != -1) {
            dp[prev_idx][curr_idx] = max(skip, take);
        }

        return max(skip, take);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(-1, 0, nums);
    }
};