class Solution {
    // int dp[101];

    // int solve(vector<int>& nums, int idx, int n) {
    //     if(idx > n) {
    //         return 0;
    //     }

    //     if(dp[idx] != -1) return dp[idx];

    //     int steal = nums[idx] + solve(nums, idx + 2, n);
    //     int skip = solve(nums, idx + 1, n);

    //     return dp[idx] = max(skip, steal);
    // }

    int solve(vector<int> nums, int start, int end) {
        int prev = 0, prevprev = 0;

        for(int i = start; i <= end; i++) {
            int skip = prev;
            int take = nums[i] + prevprev;

            prevprev = prev;
            prev = max(take, skip);
        }

        return prev;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        // if(n == 1) return nums[0];
        // if(n == 2) return max(nums[0], nums[1]);

        // memset(dp, -1, sizeof(dp));
        // int take_0th_index = solve(nums, 0, n - 2);

        // memset(dp, -1, sizeof(dp));
        // int take_1th_index = solve(nums, 1, n - 1);

        // return max(take_0th_index, take_1th_index);

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int take_first_home = solve(nums, 0, n - 2);
        int not_take_first_home = solve(nums, 1, n - 1);
        
        return max(take_first_home, not_take_first_home);
    }
};