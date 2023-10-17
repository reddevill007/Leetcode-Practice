class Solution {
    int dp[101];
    int solve(int idx, vector<int> nums, int n) {
        if(idx >= n) {
            return 0;
        }

        if(dp[idx] != -1) return dp[idx];

        int robbed = nums[idx] + solve(idx + 2, nums, n);
        int not_robbed = solve(idx + 1, nums, n);

        return dp[idx] = max(robbed, not_robbed);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));

        return solve(0, nums, n);
    }
};