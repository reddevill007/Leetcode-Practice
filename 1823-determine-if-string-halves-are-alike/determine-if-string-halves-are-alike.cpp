class Solution {
    int countVowels(int start, int end, string s) {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int count = 0;
        for (int i = start; i < end; i++) {
            char ch = s[i];
            cout << ch << " ";
            if (vowels.count(ch) > 0) {
                count++;
            }
        }
        return count;
    }

public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int i = n / 2;

        return countVowels(0, i, s) ==  countVowels(i, n, s);
    }
};