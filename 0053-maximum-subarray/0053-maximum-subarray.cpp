class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = INT_MIN;

        for(auto it: nums) {
            currSum = max(it, currSum + it);
            maxSum = max(maxSum, currSum);
        }
        
        return maxSum;
    }
};