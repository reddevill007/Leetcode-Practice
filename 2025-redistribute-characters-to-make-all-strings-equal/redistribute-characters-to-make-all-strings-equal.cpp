class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int char_count[26] = {0};
        int n = words.size();

        for(string &word: words) {
            for(char &ch: word) {
                char_count[ch - 'a']++;
            }
        }

        for(int &count: char_count) {
            if(count % n != 0) return false;
        }

        return true;
    }
};