class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int leftScore = 0, rightScore = 0;

        for(auto c: s) {
            if(c == '1') rightScore++;
        }

        int ans = 0;

        for(int i = 0; i < n - 1; i++) {
            if(s[i] == '0') leftScore++;
            else rightScore--;

            ans = max(ans, rightScore + leftScore);
        }

        return ans;
    }
};