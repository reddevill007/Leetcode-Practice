class Solution {
    int n;
    int dp[1001][1001];
    int solve(vector<vector<int>>& pairs, int prev, int curr) {
        if(curr >= n) return 0;

        if(prev != -1 && dp[curr][prev] != -1) return dp[curr][prev];

        int take = 0;
        if(prev == -1 || pairs[curr][0] > pairs[prev][1]) {
            take = 1 + solve(pairs, curr, curr + 1);
        }
        int skip = solve(pairs, prev, curr + 1);

        if(prev != -1) {
            dp[curr][prev] = max(take, skip);
        }

        return max(take, skip);
    }

public:
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp, -1, sizeof(dp));
        n = pairs.size();
        sort(begin(pairs), end(pairs));
        return solve(pairs, -1, 0);
    }
};