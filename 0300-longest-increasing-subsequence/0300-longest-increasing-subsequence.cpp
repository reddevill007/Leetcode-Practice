class Solution {
    int dp[2501][2501];
    int solve(int curr_idx, int prev_idx, vector<int>& nums) {
        if(curr_idx == nums.size()) return 0;

        if(prev_idx != -1 && dp[curr_idx][prev_idx] != -1) {
            return dp[curr_idx][prev_idx];
        }

        int take = 0;
        if(prev_idx == -1 || nums[prev_idx] < nums[curr_idx]) {
            take = 1 + solve(curr_idx + 1, curr_idx, nums);
        }

        int skip = solve(curr_idx + 1, prev_idx, nums);

        if(prev_idx != -1) {
            dp[curr_idx][prev_idx] = max(skip, take);
        }

        return max(skip, take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, nums);
    }
};