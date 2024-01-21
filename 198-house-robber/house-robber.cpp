class Solution {
    int dp[101];

    int solve(int idx, int n, vector<int> &nums) {
        if(idx >= n) {
            return 0;
        }

        if(dp[idx] != -1) return dp[idx];

        int take = nums[idx] + solve(idx + 2, n, nums);
        int not_take = solve(idx + 1, n, nums);

        return dp[idx] = max(take, not_take);
    }
public:
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        return solve(0, n, nums);
    }
};