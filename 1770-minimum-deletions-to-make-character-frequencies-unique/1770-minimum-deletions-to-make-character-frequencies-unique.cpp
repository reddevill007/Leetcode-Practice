class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0};

        for(auto ch: s) {
            freq[ch - 'a']++;
        }

        int res = 0;
        unordered_set<int> st;

        for(int i = 0; i < 26; i++) {
            while(freq[i] && st.find(freq[i]) != st.end()) {
                freq[i]--;
                res++;
            }

            st.insert(freq[i]);
        }

        return res;
    }
};