class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans(N);

        ans[0] = 1;

        for(int i = 1; i < N; i++) {
            ans[i] = nums[i - 1] * ans[i - 1];
        }

        int suffix = 1;
        
        for(int i = N - 1; i >= 0; i--) {
            ans[i] = ans[i] * suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};