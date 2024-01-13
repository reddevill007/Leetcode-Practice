class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> char_ct(26, 0);

        int m = s.length();

        int diff_char = 0;
        int n = s.length();

        for(int i = 0; i < n; i++) {
            char_ct[s[i] - 'a']++;
            char_ct[t[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++) {
            diff_char += max(0, char_ct[i]);
        }

        return diff_char;
    }
};