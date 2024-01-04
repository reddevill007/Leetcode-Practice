class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> el_count;

        for(int i = 0; i < n; i++) {
            el_count[nums[i]]++;
        }

        int ans = 0;

        for(auto it: el_count) {
            int ct = it.second;

            if(ct == 1) {
                return -1;
            }
            ans += ceil((double)ct / 3);
        }

        return ans;
    }
};