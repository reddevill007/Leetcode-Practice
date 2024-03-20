class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> count;
        int time = 0;

        for (auto c : tasks) {
            count[c]++;
        }

        priority_queue<int> pq;
        for (auto c : count) {
            pq.push(c.second);
        }

        while (!pq.empty()) {
            vector<int> v;

            for (int i = 0; i < n + 1 && !pq.empty(); i++) {
                v.push_back(pq.top() - 1);
                pq.pop();
                time++;
            }

            for (int freq : v) {
                if (freq > 0)
                    pq.push(freq);
            }

            if (pq.empty()) {
                break;
            }
            time += n + 1 - v.size();
        }
        return time;
    }
};
