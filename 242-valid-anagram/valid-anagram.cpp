class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }

        int char_map[26] = {0};

        for(int i = 0; i < s.length(); i++) {
            char_map[s[i] - 'a']++;
            char_map[t[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++) {
            if(char_map[i] > 0) return false;
        }

        return true;
    }
};