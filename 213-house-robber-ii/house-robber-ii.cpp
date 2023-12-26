class Solution {
    int dp[101];

    int solve(int idx, int n, vector<int>& nums) {
        if(idx > n) return 0;

        if(dp[idx] != -1) return dp[idx];

        int take = solve(idx + 1, n, nums);
        int not_take = nums[idx] + solve(idx + 2, n, nums);

        return dp[idx] = max(take, not_take);
    }


public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        memset(dp, -1, sizeof(dp));
        int take0th = solve(0, n - 2, nums);

        memset(dp, -1, sizeof(dp));
        int take1th = solve(1, n - 1, nums);

        return max(take0th, take1th);
    }
};