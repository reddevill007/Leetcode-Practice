class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightMax(n, 0);

        rightMax[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        }

        int leftMax = nums[0];
        int waterTrapped = 0;

        for(int i = 1; i < n; i++) {
            leftMax = max(leftMax, nums[i]);
            int currentWater = min(leftMax, rightMax[i]) - nums[i];
            waterTrapped += currentWater;
        }

        return waterTrapped;
    }
};