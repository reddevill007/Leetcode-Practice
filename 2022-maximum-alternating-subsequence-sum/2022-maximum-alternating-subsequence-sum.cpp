class Solution {
    // int n;
    // long long dp[1000001][2];

    // long long solve(int idx, vector<int> nums, bool flag) {
    //     if(idx >= n) return 0;

    //     if(dp[idx][flag] != -1) return dp[idx][flag];

    //     long long skip = solve(idx + 1, nums, flag);

    //     long long val = nums[idx];
    //     if(!flag) val = -val;

    //     long long take = solve(idx + 1, nums, !flag) + val;

    //     return dp[idx][flag] = max(take, skip);
    // }

public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        // memset(dp, -1, sizeof(dp));
        // return solve(0, nums, true);

        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

        for(int i = 1; i <= n; i++) {
            dp[i][0] = max(dp[i - 1][1] - nums[i - 1], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][0] + nums[i - 1], dp[i - 1][1]);
        }

        return max(dp[n][0], dp[n][1]);
    }
};