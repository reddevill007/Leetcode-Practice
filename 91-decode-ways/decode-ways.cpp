class Solution {
    int dp[101];
public:
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return recursiveDecode(s, 0);
    }

    int recursiveDecode(string s, int idx) {
        if(dp[idx] != -1) return dp[idx];

        if(idx == s.length()) {
            return dp[idx] = 1;
        }

        if (s[idx] == '0') {
            return dp[idx] = 0;
        }


        int ways = recursiveDecode(s, idx + 1);

        if(idx + 1 < s.length()) {
            if(s[idx] == '1' || (s[idx] == '2' && s[idx + 1] <= '6')) {
                ways += recursiveDecode(s, idx + 2);
            }
        }

        return dp[idx] = ways;
    }
};