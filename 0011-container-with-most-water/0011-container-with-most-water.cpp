class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n - 1;
        int maxArea = 0;

        while(i < j) {
            int h = min(height[i], height[j]);
            int b = j - i;

            int currArea = h * b;
            maxArea = max(maxArea, currArea);

            if(height[i] > height[j]) j--;
            else i++;
        }

        return maxArea;
    }
};