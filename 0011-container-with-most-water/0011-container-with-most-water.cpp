class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int low = 0, high = n - 1;
        int maxArea = 0;

        while (low < high) {
            int l = min(height[low], height[high]);  
            int b = high - low;                     
            int currArea = l * b;

            maxArea = max(currArea, maxArea);

            if (height[low] < height[high]) {
                low++;
            } else {
                high--;
            }
        }

        return maxArea;
    }
};
