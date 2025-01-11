class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int low = i + 1;
            int high = nums.size() - 1;

            while(low < high) {
                int sum = nums[i] + nums[low] + nums[high];

                if (sum == 0) {
                    result.push_back({nums[i], nums[low], nums[high]});
                    low++;
                    high--;

                    while (low < high && nums[low] == nums[low - 1]) low++;
                    while (low < high && nums[high] == nums[high + 1]) high--;
                }else if (sum < 0) {
                    low++;
                } else {
                    high--;
                }
            }
        }

        return result;
    }
};