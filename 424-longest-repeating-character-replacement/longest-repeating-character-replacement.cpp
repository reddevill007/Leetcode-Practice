class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        unordered_map<char, int> count;
        int maxCount = 0;
        int l = 0;

        for(int r = 0; r < s.size(); r++) {
            maxCount = max(maxCount, ++count[s[r]]);

            while(r - l + 1 - maxCount > k) {
                --count[s[l++]];
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};