class Solution {
    // int dp[101];
    // int solve(int idx, vector<int> nums, int n) {
    //     if(idx >= n) {
    //         return 0;
    //     }

    //     if(dp[idx] != -1) return dp[idx];

    //     int robbed = nums[idx] + solve(idx + 2, nums, n);
    //     int not_robbed = solve(idx + 1, nums, n);

    //     return dp[idx] = max(robbed, not_robbed);
    // }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // memset(dp, -1, sizeof(dp));

        // return solve(0, nums, n);

        // vector<int> dp(n + 1, -1);

        // dp[0] = 0;
        // dp[1] = nums[0];

        // for(int i = 2; i <= n; i++) {
        //     dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
        // }

        // return dp[n];

        if( n==1 ){
            return nums[0];
        }

        int prev2 = 0;
        int prev = nums[0];

        for(int i = 1; i < n; i++) {
            int pick = nums[i] + prev2;
            int not_pick = prev;

            int curri = max(pick, not_pick);

            prev2 = prev;
            prev = curri;
        }

        return prev;
    }
};