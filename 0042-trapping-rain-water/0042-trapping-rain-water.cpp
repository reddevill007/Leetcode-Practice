class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = height[0];
        rightMax[n - 1] = height[n - 1];

        for(int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        for(int j = n - 2; j > 0; j--) {
            rightMax[j] = max(rightMax[j + 1], height[j]);
        }

        int trappedWater = 0;
        for(int i = 1; i < n - 1; i++) {
            trappedWater += min(rightMax[i], leftMax[i]) - height[i];
        }

        return trappedWater;
    }
};