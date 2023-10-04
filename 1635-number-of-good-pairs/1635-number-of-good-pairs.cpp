class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int numberOfGoodPairs = 0;
        int n = nums.size();
        unordered_map<int, int> count;

        for(int i = 0; i < n; i++) {
            numberOfGoodPairs += count[nums[i]];
            count[nums[i]]++;
        }

        return numberOfGoodPairs;
    }
};