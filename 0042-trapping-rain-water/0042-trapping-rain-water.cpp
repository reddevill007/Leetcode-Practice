class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;
        vector<int> rightMax(n);

        int leftMax = height[0];
        rightMax[n - 1] = height[n - 1];

        for(int j = n - 2; j >= 0; j--) {
            rightMax[j] = max(rightMax[j + 1], height[j]);
        }

        int trappedWater = 0;
        for(int i = 1; i < n - 1; i++) {
            leftMax = max(leftMax, height[i]);
            trappedWater += min(rightMax[i], leftMax) - height[i];
        }

        return trappedWater;
    }
};