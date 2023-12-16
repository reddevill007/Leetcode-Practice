class Solution {
    // a + b = c
    // a = c - a
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> compliment;

        for(int i = 0; i < n; i++) {
            int left = target - nums[i];
            
            if(compliment.contains(left) && compliment[left] != i) {
                return {i, compliment[left]};
            }

            compliment[nums[i]] = i;
        }

        return {};
    }
};