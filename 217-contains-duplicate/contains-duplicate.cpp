class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> seen;

        for(int i = 0; i < nums.size(); i++) {
            if(seen.insert(nums[i]).second == false) return true;
        }

        return false;
    }
};