class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> char_ct;

        for(auto ch: s) {
            char_ct[ch]++;
        }

        for(auto it: char_ct) {
            pq.push({it.second, it.first});
        }

        string res = "";

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            for(int i = 0; i < top.first; i++) {
                res.push_back(top.second);
            }
        }

        return res;
    }
};