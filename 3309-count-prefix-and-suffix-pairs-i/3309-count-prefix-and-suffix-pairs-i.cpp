class Solution {
    bool isPrefixAndSuffix(string a, string b) {
        int n = a.length();
        int m = b.length();

        if(n > m) return false;

        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) return false;
        }

        for (int i = 0; i < n; i++) {
            if (a[i] != b[m - n + i]) return false;
        }

        return true;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(isPrefixAndSuffix(words[i], words[j])) ans++;
            }
        }

        return ans;
    }
};