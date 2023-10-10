class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = n;

        set<int> unique(nums.begin(), nums.end());
        vector<int> newNums;

        for(int num: unique) {
            newNums.push_back(num);
        }

        for(int i = 0; i < newNums.size(); i++) {
            int L = newNums[i];
            int R = L + n - 1;

            int j = upper_bound(begin(newNums), end(newNums), R) - begin(newNums);
            int within_range = j - i;
            int outof_range = n - within_range;

            ans = min(ans, outof_range);
        }

        return ans;
    }
};