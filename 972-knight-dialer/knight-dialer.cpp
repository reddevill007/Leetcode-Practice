class Solution {
    int MOD = 1e9 + 7;

    vector<vector<int>> adj = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };

    int dp[5001][10];

    int solve(int n, int cell) {
        if(n == 0) return 1;

        if(dp[n][cell] != -1) return dp[n][cell];

        int ans = 0;

        for(int nextCell: adj[cell]) {
            ans = (ans + solve(n - 1, nextCell)) % MOD;
        }

        return dp[n][cell] = ans;
    }
public:
    int knightDialer(int n) {
        int result = 0;

        memset(dp, -1, sizeof(dp));

        for(int i = 0; i <= 9; i++) {
            result = (result + solve(n - 1, i)) % MOD;
        }

        return result;
    }
};