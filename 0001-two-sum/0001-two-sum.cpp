class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_idx_mp;

        for(int i = 0; i < nums.size(); i++) {
            nums_idx_mp[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];

            if(nums_idx_mp.contains(comp) && nums_idx_mp[comp] != i) {
                return {nums_idx_mp[comp], i};
            }
        }

        return {};
    }
};