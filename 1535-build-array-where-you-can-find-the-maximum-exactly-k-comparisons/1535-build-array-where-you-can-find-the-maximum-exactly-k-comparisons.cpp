class Solution {
    int dp[51][51][101];
    int MOD = 1e9 + 7;

    int solve(int idx, int search_cost, int max_so_far, int len, int range, int expected_cost) {
        if(idx == len) {
            if(search_cost == expected_cost) {
                return 1;
            }
            else {
                return 0;
            }
        }

        if(dp[idx][search_cost][max_so_far] != -1) return dp[idx][search_cost][max_so_far];

        int result = 0;

        for(int i = 1; i <= range; i++) {
            if(i > max_so_far) {
                result = (result + solve(idx + 1, search_cost + 1, i, len, range, expected_cost)) % MOD;
            } else {
                result = (result + solve(idx + 1, search_cost, max_so_far, len, range, expected_cost)) % MOD;
            }
        }

        return dp[idx][search_cost][max_so_far] = result;
    }

public:
    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, n, m, k);
    }
};