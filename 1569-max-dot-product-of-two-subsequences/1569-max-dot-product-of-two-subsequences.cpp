class Solution {
public:
    int dp[501][501][2];
    int helper(int i, int j, vector<int>& nums1, vector<int>& nums2, int taken_element) {
        if(i == nums1.size() || j == nums2.size()) {
            if(taken_element == 1) return 0;
            return -1; 
        }

        if(dp[i][j][taken_element] != INT_MIN) return dp[i][j][taken_element];

        int op1 = nums1[i] * nums2[j] + helper(i + 1, j + 1, nums1, nums2, 1);
        int op2 = helper(i + 1, j, nums1, nums2, taken_element);
        int op3 = helper(i, j + 1, nums1, nums2, taken_element);

        return dp[i][j][taken_element] = max(op1, max(op2, op3));
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                dp[i][j][0] = INT_MIN;
                dp[i][j][1] = INT_MIN;
            }
        }

        int ans = helper(0, 0, nums1, nums2, 0);

        if(ans == -1) {
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());

            return max(nums1.front() * nums2.back(), nums2.front() * nums1.back());
        }

        return ans;
    }
};