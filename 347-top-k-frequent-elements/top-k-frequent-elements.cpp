class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int prevEl = nums[0];
        int count = 1;

        priority_queue<pair<int, int> > pq;

        for(int i = 1; i < n; i++) {
            if(nums[i] == prevEl) {
                count++;
            } else {
                pq.push({count, prevEl});
                prevEl = nums[i];
                count = 1;
            }
        }


        pq.push({count, prevEl});
        vector<int> ans;

        for(int i = 0; i < k; i++) {
            int el = pq.top().second;
            ans.push_back(el);
            pq.pop();
        }

        return ans;
    }
};