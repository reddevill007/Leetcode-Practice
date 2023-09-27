class Solution {
public:
    char findTheDifference(string s, string t) {
        char xorr = 0;

        for(auto ch: s) {
            xorr = xorr ^ ch;
        }

        for(auto ch: t) {
            xorr = xorr ^ ch;
        }

        return xorr;
    }
};