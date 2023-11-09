class Solution {
    int MOD = 1e9 + 7;
public:
    int countHomogenous(string s) {
        int answer = 0;
        int len = 0;

        for(int i = 0; i < s.length(); i++) {
            if(i > 0 && s[i] == s[i - 1]) {
                len++;
            } else {
                len = 1;
            }

            answer = (answer +  len) % MOD;
        }

        return answer;
    }
};