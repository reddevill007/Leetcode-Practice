class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int prod1 = nums[0]*nums[1];
        int prod2 = nums[n - 1]*nums[n - 2];

        return prod2 - prod1;
    }
};