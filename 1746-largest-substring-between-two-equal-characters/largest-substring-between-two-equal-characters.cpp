class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();
        int largestSubStr = -1;

        vector<int> lastSeen(26, -1);

        for(int i = 0; i < n; i++) {
            char ch = s[i];

            if(lastSeen[ch - 'a'] != -1) {
                int currLargestSubStr = i - lastSeen[ch - 'a'] - 1;
                largestSubStr = max(largestSubStr, currLargestSubStr);
            } else {
                lastSeen[ch - 'a'] = i;
            }
        }

        return largestSubStr;

    }
};