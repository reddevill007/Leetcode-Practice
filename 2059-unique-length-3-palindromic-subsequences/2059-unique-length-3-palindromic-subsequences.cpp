class Solution {
public:
    int countPalindromicSubsequence(string s) {
        set<string> st;
        int n = s.length();

        // Iterate over all characters as the middle character
        for (int i = 1; i < n - 1; i++) {
            set<char> leftChars, rightChars;

            // Collect distinct characters on the left of s[i]
            for (int j = 0; j < i; j++) {
                leftChars.insert(s[j]);
            }

            // Collect distinct characters on the right of s[i]
            for (int j = i + 1; j < n; j++) {
                rightChars.insert(s[j]);
            }

            // Check palindromic subsequences of length 3
            for (char c : leftChars) {
                if (rightChars.find(c) != rightChars.end()) {
                    string pal = {c, s[i], c};
                    st.insert(pal);
                }
            }
        }

        return st.size();
    }
};
