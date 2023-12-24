class Solution {
    string createAlterntiveString(int n, char startWith) {
        string formed = "";
        formed.push_back(startWith);

        for(int i = 1; i < n; i++) {
            char prevChar = formed[i - 1];
            char toBePushed  = prevChar == '1' ? '0' : '1';
            formed.push_back(toBePushed);
        }

        return formed;
    }

public:
    int minOperations(string s) {
        int n = s.length();

        string finalStringStaringWith1 = createAlterntiveString(n, '1');
        string finalStringStaringWith0 = createAlterntiveString(n, '0');

        int diff1 = 0;
        int diff0 = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] != finalStringStaringWith1[i]) diff1++;
            if(s[i] != finalStringStaringWith0[i]) diff0++;
        }

        return min(diff1, diff0);
    }
};