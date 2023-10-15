class Solution {
    int n;
    int MOD = 1e9 + 7;
    int dp[501][501];

    int solve(int idx, int steps) {
        // base case 1 ->  out of bount
        if(idx < 0 || idx >= n) {
            return 0;
        }

        //  base case 2 -> steps 0 && reched idx 0
        if(steps == 0) {
            return idx == 0;
        }

        //  if already calculated
        if(dp[idx][steps] != -1) return dp[idx][steps];

        //  try all possible options
        int result = solve(idx - 1, steps - 1) % MOD;
        result = (result + solve(idx + 1, steps - 1)) % MOD;
        result = (result + solve(idx, steps - 1)) % MOD;

        //  return sum of all options that are valid
        return dp[idx][steps] = (result) % MOD;
    }
public:
    int numWays(int steps, int arrLen) {
        n = min(arrLen, steps / 2 + 1);
        memset(dp, -1, sizeof(dp));
        return solve(0, steps);
    }
};