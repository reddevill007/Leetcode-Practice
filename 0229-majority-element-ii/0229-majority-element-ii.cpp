class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> element_count;
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            element_count[nums[i]]++;
        }

        for(auto it: element_count) {
            if(it.second > n / 3) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};