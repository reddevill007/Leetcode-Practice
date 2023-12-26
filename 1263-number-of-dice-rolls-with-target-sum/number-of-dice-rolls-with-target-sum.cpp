class Solution {
    int MOD = 1e9 + 7;
    int dp[31][1001];

    int solve(int dices, int faces, int target) {
        if(target == 0 && dices == 0) return 1;
        if(target <= 0 || dices == 0) return 0;

        if(dp[dices][target] != -1) return dp[dices][target] % MOD; 

        int ans = 0;
        for(int i = 1; i <= faces; i++) {
            ans = (ans + solve(dices - 1, faces, target - i)) % MOD;
        }

        dp[dices][target] = ans % MOD;
        return ans;
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(n, k, target);
    }
};