class Solution {
public:
    int MOD = 1e9 + 7;
    int countHomogenous(string s) {
        int n = s.length();
        int answer = 0;
        int len = 0;

        for(int i = 0; i < n; i++) {
            if(i > 0 && s[i] == s[i - 1]) {
                len += 1;
            } else {
                len = 1;
            }

            answer = (answer +  len) % MOD;
        }

        return answer;
    }
};