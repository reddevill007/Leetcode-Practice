class Solution {
    int dp[2501][2501];
    int lis(vector<int>& nums, int prev_idx, int curr_idx) {
        if(curr_idx == nums.size())
           return 0;
        
        if(prev_idx != -1 && dp[prev_idx][curr_idx] != -1)
            return dp[prev_idx][curr_idx];
        
        int taken = 0;
        if(prev_idx == -1 || nums[curr_idx] > nums[prev_idx])
            taken = 1 + lis(nums, curr_idx, curr_idx+1);
        
        int not_taken = lis(nums, prev_idx, curr_idx+1);
        
        if(prev_idx != -1)
            dp[prev_idx][curr_idx] =  max(taken, not_taken);
        
        return max(taken, not_taken);

    }
public:
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return lis(nums, -1, 0);
    }
};