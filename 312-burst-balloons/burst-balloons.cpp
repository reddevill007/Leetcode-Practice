class Solution {
    int dp[301][301];

    int maxCoinsHelper(int i, int j, vector<int> &nums) {
        if (i > j) return 0;
        int maxCoins = INT_MIN;

        if(dp[i][j] != -1) return dp[i][j];
        
        // Iterate through each possible balloon to burst last
        for (int k = i; k <= j; k++) {
            // Calculate the coins obtained by bursting the k-th balloon last
            int coins = nums[i - 1] * nums[k] * nums[j + 1];
            
            // Recursively calculate the maximum coins for the remaining balloons
            int remainingCoins = maxCoinsHelper(i, k - 1, nums) + maxCoinsHelper(k + 1, j, nums);
            
            // Update the maximum coins
            maxCoins = max(maxCoins, coins + remainingCoins);
        }
        
        return dp[i][j] = maxCoins;
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
    
        // Add 1 to the beginning and end of the nums array
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        // Call the helper function to compute the maximum coins
        return maxCoinsHelper(1, n, nums);
    }
};