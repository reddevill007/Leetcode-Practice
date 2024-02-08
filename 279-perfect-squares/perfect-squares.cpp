class Solution {
    int dp[10001];

    int solve(int n) {
        if(n == 0) return 0;
        if (n < 0) return INT_MAX;
        if(dp[n] != -1) return dp[n];
        int minCount = INT_MAX;

        for(int i = 1; i*i <= n; i++) {
            minCount = min(minCount, 1 + solve(n - i*i));
        }

        return dp[n] = minCount;
    }
public:
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};