class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> el_freq;

        for(auto num: nums) {
            el_freq[num]++;
        }

        priority_queue<pair<int, int> > pq;

        for(auto mp: el_freq) {
            pq.push({mp.second, mp.first});
        }

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            int el = pq.top().second;
            ans.push_back(el);
            pq.pop();
        }

        return ans;
    }
};