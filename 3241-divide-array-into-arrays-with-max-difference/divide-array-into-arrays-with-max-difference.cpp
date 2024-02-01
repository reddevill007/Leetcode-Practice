class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0;

        for(int i = 0; i < n - 2; i+=3) {
            if(nums[i + 2] - nums[i] > k) {
                return {};
            }
            result.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return result;
    }
};