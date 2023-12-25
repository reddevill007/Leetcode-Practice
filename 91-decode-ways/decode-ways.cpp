class Solution {
    int dp[101];
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);

        dp[n] = 1;

        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + 1];
                if(i + 1 < n) {
                    if(s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
                        dp[i] += dp[i + 2];
                    }
                }
            }
        }

        return dp[0];
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