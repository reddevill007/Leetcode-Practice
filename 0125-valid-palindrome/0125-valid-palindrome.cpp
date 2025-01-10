class Solution {
private:
    bool isalnum_custom(char ch) {
        if (ch >= '0' && ch <= '9') {
            return true;
        }
        if (ch >= 'A' && ch <= 'Z') {
            return true;
        }
        if (ch >= 'a' && ch <= 'z') {
            return true;
        }
        return false;
    }

public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() -1;

        while(i < j) {
            if(!isalnum_custom(s[i])) {
                i++;
            } else if(!isalnum_custom(s[j])) {
                j--;
            } else {
                if(tolower(s[i]) != tolower(s[j])) return false;
                i++;
                j--;
            }
        }

        return true;
    }
};