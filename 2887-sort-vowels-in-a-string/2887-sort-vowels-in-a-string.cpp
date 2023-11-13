class Solution {
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            return true;
        }
        return false;
    }
public:
    string sortVowels(string s) {
        string res;
        for(int i = 0; i < s.length(); i++) {
            if(isVowel(s[i])) {
                res.push_back(s[i]);
            }
        }

        sort(res.begin(), res.end());
        int j = 0;

        for(int i = 0; i < s.length(); i++) {
            if(isVowel(s[i])) {
                s[i] = res[j];
                j++;
            }
        }

        return s;
    }
};