class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> char_ct;

        int m = s.length();
        int n = t.length();

        int diff_char = 0;

        for(int i = 0; i < n; i++) {
            char_ct[s[i]]++;
            char_ct[t[i]]--;
        }

        for(auto it: char_ct) {
            diff_char += max(0, it.second);
        }

        return diff_char;
    }
};