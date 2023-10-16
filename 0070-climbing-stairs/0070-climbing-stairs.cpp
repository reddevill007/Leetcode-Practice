class Solution {
    int dp[46];

    int helper(int steps, int n) {
        if(steps > n) return 0;
        if(steps == n) return 1;

        if(dp[steps] != -1) return dp[steps];

        int one_step = helper(steps + 1, n);
        int two_step = helper(steps + 2, n);

        return dp[steps] = one_step + two_step;
    }
public:
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(0, n);
    }
};