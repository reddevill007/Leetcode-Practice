class Solution {
    // int n;
    // int dp[1001][1001];
    // int solve(vector<vector<int>>& pairs, int prev, int curr) {
    //     if(curr >= n) return 0;

    //     if(prev != -1 && dp[curr][prev] != -1) return dp[curr][prev];

    //     int take = 0;
    //     if(prev == -1 || pairs[curr][0] > pairs[prev][1]) {
    //         take = 1 + solve(pairs, curr, curr + 1);
    //     }
    //     int skip = solve(pairs, prev, curr + 1);

    //     if(prev != -1) {
    //         dp[curr][prev] = max(take, skip);
    //     }

    //     return max(take, skip);
    // }

public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // memset(dp, -1, sizeof(dp));
        // n = pairs.size();
        // sort(begin(pairs), end(pairs));
        // return solve(pairs, -1, 0);

        
        int n = pairs.size();
        vector<int> dp(n, 1);
        sort(begin(pairs), end(pairs));

        int maxLts = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxLts = max(maxLts, dp[i]);
                }
            }
        }

        return maxLts;
    }
};