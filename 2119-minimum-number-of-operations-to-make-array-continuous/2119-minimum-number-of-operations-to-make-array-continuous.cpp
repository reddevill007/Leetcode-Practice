class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int minWindow = n;

        set<int> unique(nums.begin(), nums.end());
        vector<int> newNums;

        for(int num: unique) {
            newNums.push_back(num);
        }

        int end = 0;

        for(int start = 0; start < newNums.size(); start++) {
            while(end < newNums.size() && newNums[end] < newNums[start] + n) {
                end++;
            }

            int window = end - start;

            minWindow = min(minWindow, n - window);
        }

        return minWindow;
    }
};