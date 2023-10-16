class Solution {
    // int dp[46];

    // int helper(int steps, int n) {
    //     if(steps > n) return 0;
    //     if(steps == n) return 1;

    //     if(dp[steps] != -1) return dp[steps];

    //     int one_step = helper(steps + 1, n);
    //     int two_step = helper(steps + 2, n);

    //     return dp[steps] = one_step + two_step;
    // }

public:
    int climbStairs(int n) {
        // memset(dp, -1, sizeof(dp));
        // return helper(0, n);

        if(n < 3) return n;

        vector<int> dp(n + 1, -1);

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};