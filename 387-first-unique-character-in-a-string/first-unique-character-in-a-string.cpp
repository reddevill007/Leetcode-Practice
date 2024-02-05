class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> char_ct(26, 0);

        for(char ch: s) {
            char_ct[ch - 'a']++;
        }

        for(int i = 0; i < s.length(); i++) {
            if(char_ct[s[i] - 'a'] == 1) return i;
        }

        return -1;
    }
};