class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int &num : nums) {
            mp[num]++;
        }

        int maxSize = 0;

        for(auto it: mp) {
            int ct = it.second;
            maxSize = max(maxSize, ct);
        }

        vector<vector<int>> ans(maxSize);

        for(auto it: mp) {
            int el = it.first;
            int ct = it.second;

            for(int i = 0; i < ct; i++) {
                ans[i].push_back(el);
            }
        }

        return ans;
    }
};