class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_idx_mp;

        for(int i = 0; i < nums.size(); i++) {
            cout << "Pushing " << nums[i] << " " << i << endl;
            nums_idx_mp.insert({nums[i], i});
        }

        for(int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];

            if(nums_idx_mp.find(comp) != nums_idx_mp.end() && nums_idx_mp.find(comp)->second != i) {
                cout << "found " << nums_idx_mp.find(comp)->second << " " << i << endl;
                return {nums_idx_mp.find(comp)->second, i};
            }
        }

        return {};
    }
};