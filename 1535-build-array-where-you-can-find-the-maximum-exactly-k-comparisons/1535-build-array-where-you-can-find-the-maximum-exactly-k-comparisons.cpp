class Solution {
public:
    int MOD = 1e9 + 7;
    // dp[idx][searchCost][maxSoFar]
    int dp[51][51][101];

    int solve(int idx, int searchCost, int maxSoFar, int length, int range, int expectedCost) {
        if(idx == length) {
            if(searchCost == expectedCost) return 1;
            return 0;
        }

        if(dp[idx][searchCost][maxSoFar] != -1) return dp[idx][searchCost][maxSoFar];

        int result = 0;

        for(int i = 1; i <= range; i++) {
            if(i > maxSoFar) {
                result = (result + solve(idx + 1, searchCost + 1, i, length, range, expectedCost)) % MOD;
            } else {
                result = (result + solve(idx + 1, searchCost, maxSoFar, length, range, expectedCost)) % MOD;
            }
        }

        return dp[idx][searchCost][maxSoFar] = result % MOD;
    }

    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, n, m, k);
    }
};