class Solution {
    // int dp[101];

    // int solve(vector<int>& nums, int idx, int n) {
    //     if(idx > n) {
    //         return 0;
    //     }

    //     if(dp[idx] != -1) return dp[idx];

    //     int steal = nums[idx] + solve(nums, idx + 2, n);
    //     int skip = solve(nums, idx + 1, n);

    //     return dp[idx] = max(skip, steal);
    // }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        // if(n == 1) return nums[0];
        // if(n == 2) return max(nums[0], nums[1]);

        // memset(dp, -1, sizeof(dp));
        // int take_0th_index = solve(nums, 0, n - 2);

        // memset(dp, -1, sizeof(dp));
        // int take_1th_index = solve(nums, 1, n - 1);

        // return max(take_0th_index, take_1th_index);

        vector<int> dp(n + 1, 0);

        dp[0] = 0;

        // Case-1 (Take from 1st House - Hence skip the last house)
        for(int i = 1; i <= n - 1; i++) {
            int skip = dp[i - 1];
            int not_skip = nums[i - 1] + ((i - 2) >= 0 ? dp[i - 2] : 0);

            dp[i] = max(skip, not_skip);
        }

        int res1 = dp[n - 1];

        dp.clear();
        dp[0] = 0;
        dp[1] = 0;

        for(int i = 2; i <= n; i++) {
            int skip = dp[i - 1];
            int not_skip = nums[i - 1] + ((i - 2) >= 0 ? dp[i - 2] : 0);

            dp[i] = max(skip, not_skip);
        }

        int res2 = dp[n];

        return max(res1, res2);
    }
};